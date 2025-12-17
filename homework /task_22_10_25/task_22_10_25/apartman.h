#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int age;

public:
    Person() : name(nullptr), age(0) {}

    Person(const char* n, int a) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Person(const Person& obj) : age(obj.age) {
        if (obj.name) {
            
            name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name);
        } else name = nullptr;
        
    }

    Person& operator=(const Person& obj) {
        if (this == &obj)
            return *this;

        delete[] name;

        age = obj.age;
        
        if (obj.name) {
            name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name);
        } else name = nullptr;

        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void print() const {
        cout << "  ім'я: " << (name ? name : "невідомо")
        
        
        
             << "  вік: " << age << endl;
    }
};

class Apartment {
private:
    int number;
    Person* people;
    int peopleCount;

public:
    Apartment() : number(0), people(nullptr), peopleCount(0) {}

    Apartment(int number, int count, const Person* srcPeople)
        : number(number), peopleCount(count)
    {
        if (peopleCount > 0 && srcPeople) {
            people = new Person[peopleCount];
            
            for (int i = 0; i < peopleCount; ++i)
                people[i] = srcPeople[i];
        } else people = nullptr;
    }

    Apartment(const Apartment& obj)
    
        : number(obj.number), peopleCount(obj.peopleCount)
    {
        if (peopleCount > 0 && obj.people) {
            people = new Person[peopleCount];
            for (int i = 0; i < peopleCount; ++i)
                
                people[i] = obj.people[i];
        } else people = nullptr;
    }

    Apartment& operator=(const Apartment& obj) {
        if (this == &obj)
            return *this;

        delete[] people;

        this->number = obj.number;
        this->peopleCount = obj.peopleCount;
        

        if (peopleCount > 0 && obj.people) {
            
            this->people = new Person[peopleCount];
            for (int i = 0; i < peopleCount; ++i)
                this->people[i] = obj.people[i];
            
        } else this->people = nullptr;

        return *this;
    }

    ~Apartment() {
        delete[] people;
    }

    void print() const {
        
        cout << "мвартира " << number
        
             << "  mешканців: " << peopleCount << endl;
        
        
        for (int i = 0; i < peopleCount; ++i)
            
            people[i].print();
        cout << endl;
        
    }
};


class House {
private:
    
    char* address;
    Apartment* flats;
    int flatCount;

public:
    House() : address(nullptr), flats(nullptr), flatCount(0) {}

    House(const char* addr, int count, const Apartment* srcFlats)
        : flatCount(count)
    {
        address = new char[strlen(addr) + 1];
        strcpy(address, addr);

        if (flatCount > 0 && srcFlats) {
            flats = new Apartment[flatCount];
            for (int i = 0; i < flatCount; ++i)
                
                flats[i] = srcFlats[i];
        } else flats = nullptr;
    }

    House(const House& obj)
        : flatCount(obj.flatCount)
    {
        if (obj.address) {
            
            address = new char[strlen(obj.address) + 1];
            strcpy(address, obj.address);
        } else address = nullptr;

        if (flatCount > 0 && obj.flats) {
            flats = new Apartment[flatCount];
            for (int i = 0; i < flatCount; ++i)
                
                flats[i] = obj.flats[i];
        } else flats = nullptr;
    }

    House& operator=(const House& obj) {
        if (this == &obj)
            return *this;

        delete[] address;
        delete[] flats;

        this->flatCount = obj.flatCount;

        if (obj.address) {
            this->address = new char[strlen(obj.address) + 1];
            strcpy(this->address, obj.address);
        } else this->address = nullptr;

        if (flatCount > 0 && obj.flats) {
            this->flats = new Apartment[flatCount];
            for (int i = 0; i < flatCount; ++i)
                this->flats[i] = obj.flats[i];
        } else this->flats = nullptr;

        return *this;
    }

    ~House() {
        delete[] address;
        delete[] flats;
    }

    void print() const {
        cout << "будинок за адресою: "
             << (address ? address : "невідомо") << endl;
        cout << "кількість квартир: " << flatCount << endl << endl;

        for (int i = 0; i < flatCount; ++i)
            flats[i].print();
    }
};
