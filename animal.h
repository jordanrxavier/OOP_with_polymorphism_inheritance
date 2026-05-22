#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

// base class - all animals have a name and can speak
class Animal {
public:
    string name;
    Animal(string n) : name(n) {}  // constructor - sets name
    virtual void speak() { cout << "..." << endl; }  // virtual so derived classes can override
    virtual ~Animal() {}           // virtual destructor - important for polymorphism
};

// Cat inherits from Animal
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}   // passes name up to Animal
    void speak() override { cout << name << ": Meow!" << endl; }  // overrides Animal's speak
};

// Dog inherits from Animal
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void speak() override { cout << name << ": Woof!" << endl; }
};

// Bird inherits from Animal
class Bird : public Animal {
public:
    Bird(string n) : Animal(n) {}
    void speak() override { cout << name << ": Tweet!" << endl; }
};
#endif