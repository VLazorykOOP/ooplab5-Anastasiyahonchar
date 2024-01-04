/*Створити карту й використовую композицію - колоду карт. Конструктори 
колоди повинні ініціалізувати колоду впорядковане й випадковим образом. Створити 
похідний клас від колоди - пасьянс, у якім вибираються по три карти й, якщо дві крайні 
одного кольору, то їх викидають. Усю колоду проходять три рази.*/

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int numSuits = 4;
const int numRanks = 13;
const int size = numSuits * numRanks;

struct Card{
    string suit;
    string rank;
};

class Deck{
protected:
    Card cards[size];
    int top;

public:
    Deck(bool shuffled = false){
        top = 0;
        initializeDeck();
        if (shuffled) {
            shuffleDeck();
        }
    }

    void initializeDeck(){
        string suits[numSuits] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[numRanks] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

        int index = 0;
        for (int s = 0; s < numSuits; s++){
            for (int r = 0; r < numRanks; r++){
                cards[index].suit = suits[s];
                cards[index].rank = ranks[r];
                index++;
            }
        }
    }

    void shuffleDeck(){
        srand(time(0));
        for (int i = 0; i < size; i++){
            int swap = rand() % size;
            Card temp = cards[i];
            cards[i] = cards[swap];
            cards[swap] = temp;
        }
    }

    void print(){
        for (int i = 0; i < size; i++){
            cout << cards[i].rank << " " << cards[i].suit << endl;
        }
    }

    Card* getCards(){
        return cards;
    }
};

class Solitaire : public Deck{
public:
    Solitaire(bool shuffled = false) : Deck(shuffled) {}

    void playSolitaire(){
        for (int i = 0; i < 3; i++){
            removeCards();
        }
    }

    void removeCards(){
        int j = 0;
        for (int i = 0; i < size; i++){
            if (i < size - 2) {
                if ((cards[i].suit == "Hearts" || cards[i].suit == "Diamonds") &&
                    (cards[i + 2].suit == "Hearts" || cards[i + 2].suit == "Diamonds")){
                    i += 2;
                } else if ((cards[i].suit == "Clubs" || cards[i].suit == "Spades") &&
                           (cards[i + 2].suit == "Clubs" || cards[i + 2].suit == "Spades")){
                    i += 2;
                } else{
                    cards[j].suit = cards[i].suit;
                    cards[j].rank = cards[i].rank;
                    j++;
                }
            } else{
                cards[j].suit = cards[i].suit;
                cards[j].rank = cards[i].rank;
                j++;
            }
        }

        for (int i = j; i < size; i++) {
            cards[i].suit = "";
            cards[i].rank = "";
        }
    }
};

int main(){
    Solitaire solitaire(true);
    cout << "Initial Deck:" << endl;
    solitaire.print();
    cout << "\nPlaying Solitaire..." << endl;
    solitaire.playSolitaire();
    cout << "\nFinal Deck:" << endl;
    solitaire.print();

    return 0;
}

