/*Створити ієрархію класів вектор і безпечний вектор з перевіркою виходу за 
межі. Безпечний вектор визначає змінні нижня й верхня межа Перевизначити вивід у 
потік і введення з потоку, конструктор копіювання, оператор присвоювання через 
відповідні функції базового класу. */
#include <iostream>
#include <vector>

using namespace std;

class Vector{
protected:
    vector<int> data;

public:
    Vector() {}
    Vector(const vector<int>& v) : data(v) {}
    Vector(const Vector& other) : data(other.data) {}

    Vector& operator=(const Vector& other){
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    void push_back(int value){
        data.push_back(value);
    }

    int out(int index) const{
        if (index < 0 || index >= data.size()){
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    int size() const{
        return data.size();
    }

    friend ostream& operator<<(ostream& os, const Vector& vec){
    for (int i = 0; i < vec.data.size(); i++) {
        os << vec.data[i] << " ";
    }
    return os;
    }   

    friend istream& operator>>(istream& is, Vector& vec){
        int value;
        while (is >> value) {
            vec.data.push_back(value);
        }
        return is;
    }
};

class SafeVector : public Vector{
private:
    int lower, upper;

public:
    SafeVector() : lower(0), upper(100) {}
    SafeVector(const vector<int>& v, int lower, int upper) : Vector(v), lower(lower), upper(upper) {}
    SafeVector(const SafeVector& other) : Vector(other), lower(other.lower), upper(other.upper) {}

    SafeVector& operator=(const SafeVector& other){
        if (this != &other){
            Vector::operator=(other);
            lower = other.lower;
            upper = other.upper;
        }
        return *this;
    }

    int out(int index) const{
        if (index < lower || index >= upper || index >= data.size()){
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main(){
    Vector vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "Vector: " << vec << endl;

    SafeVector safeVec;
    safeVec.push_back(100);
    safeVec.push_back(200);
    safeVec.push_back(300);
    cout << "SafeVector: " << safeVec << endl;

    try{
        cout << "Element at index 1 in Vector: " << vec.out(1) << endl;
        cout << "Element at index 5 in SafeVector: " << safeVec.out(5) << endl;
    } catch (const out_of_range& e){
        cout << e.what() << endl;
    }

    return 0;
}
