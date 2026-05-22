#include <iostream>
#include <vector>
#include "animal.h"
using namespace std;

int main() {

    // base class pointer holding a derived object
    // this is polymorphism - Animal pointer but Cat behavior
    Animal* a = new Cat("Luna");
    a->speak();   // calls Cat's speak not Animal's
    delete a;     // virtual destructor makes sure Cat cleans up

    cout << endl;

    // vector of Animal pointers - can hold any derived type
    vector<Animal*> shelter;
    shelter.push_back(new Cat("Mochi"));
    shelter.push_back(new Dog("Rex"));
    shelter.push_back(new Cat("Bella"));
    shelter.push_back(new Bird("Tweety"));
    shelter.push_back(new Dog("Buddy"));

    // loop through and call speak on each one
    // even though they are all Animal* the right speak() runs
    // because speak() is virtual - this is runtime polymorphism
    cout << "All animals in the shelter:" << endl;
    for (Animal* animal : shelter) {
        animal->speak();
    }

    cout << endl;

    // clean up all the heap memory
    // virtual destructor means each object's own destructor runs
    for (Animal* animal : shelter) {
        delete animal;
    }

    return 0;
}