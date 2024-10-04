Клас "Людина"
#include <iostream>
#include <cstring>

class Person {
private:
    char* name;
    int age;

public:
    Person() {
        name = nullptr;
        age = 0;
    }

    Person(const char* personName, int personAge) {
        age = personAge;
        name = new char[strlen(personName) + 1];
        strcpy(name, personName);
    }

    Person(const Person& other) {
        age = other.age;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~Person() {
        delete[] name;
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
Клас "Квартира"
class Apartment {
private:
    Person* people;
    int numberOfPeople;

public:
    Apartment() {
        people = nullptr;
        numberOfPeople = 0;
    }

    Apartment(Person* persons, int num) {
        numberOfPeople = num;
        people = new Person[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            people[i] = persons[i];
        }
    }

    Apartment(const Apartment& other) {
        numberOfPeople = other.numberOfPeople;
        people = new Person[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            people[i] = other.people[i];
        }
    }

    ~Apartment() {
        delete[] people;
    }

    void display() const {
        std::cout << "Apartment with " << numberOfPeople << " people:" << std::endl;
        for (int i = 0; i < numberOfPeople; i++) {
            people[i].display();
        }
    }
};
Клас "Дім"
class House {
private:
    Apartment* apartments;
    int numberOfApartments;

public:
    House() {
        apartments = nullptr;
        numberOfApartments = 0;
    }

    House(Apartment* apts, int num) {
        numberOfApartments = num;
        apartments = new Apartment[numberOfApartments];
        for (int i = 0; i < numberOfApartments; i++) {
            apartments[i] = apts[i];
        }
    }

    House(const House& other) {
        numberOfApartments = other.numberOfApartments;
        apartments = new Apartment[numberOfApartments];
        for (int i = 0; i < numberOfApartments; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    ~House() {
        delete[] apartments;
    }

    void display() const {
        std::cout << "House with " << numberOfApartments << " apartments:" << std::endl;
        for (int i = 0; i < numberOfApartments; i++) {
            apartments[i].display();
        }
    }
};
