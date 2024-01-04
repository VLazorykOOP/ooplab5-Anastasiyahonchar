/*Створити класи транспортні засоби, автомобіль, вантажівка, пароплав і 
літак. Створити з них ієрархію. Визначити функції друку, конструктори й деструктори. 
Написати програму тестування всіх можливостей цього класу.*/
#include <iostream>
#include <string>

using namespace std;

class Transport{
public:
    string type;
    int year;
    Transport(string t, int y) : type(t), year(y) {}
    void print(){
        cout << "Type: " << type << "\nYear: " << year << endl;
    }
    ~Transport() {}
};

class Car : public Transport{
public:
    string model;
    Car(string t, int y, string m) : Transport(t, y), model(m) {}
    void print(){
        Transport::print();
        cout << "Model: " << model << endl;
    }
    ~Car() {}
};

class Truck : public Transport{
public:
    int capacity;
    Truck(string t, int y, int c) : Transport(t, y), capacity(c) {}
    void print(){
        Transport::print();
        cout << "Capacity: " << capacity << " tons" << endl;
    }
    ~Truck() {}
};

class Steamboat : public Transport{
public:
    string manufacturer;
    Steamboat(string t, int y, string m) : Transport(t, y), manufacturer(m) {}
    void print(){
        Transport::print();
        cout << "Manufacturer: " << manufacturer << endl;
    }
    ~Steamboat() {}
};

class Airplane : public Transport{
public:
    string airline;
    Airplane(string t, int y, string a) : Transport(t, y), airline(a) {}
    void print(){
        Transport::print();
        cout << "Airline: " << airline << endl;
    }
    ~Airplane() {}
};

int main(){
    Car car("Car", 2020, "Toyota");
    Truck truck("Truck", 2018, 10);
    Steamboat boat("Boat", 2015, "qwerty");
    Airplane plane("Plane", 2019, "Airline abc");

    car.print();
    cout << endl;
    truck.print();
    cout << endl;
    boat.print();
    cout << endl;
    plane.print();

    return 0;
}
