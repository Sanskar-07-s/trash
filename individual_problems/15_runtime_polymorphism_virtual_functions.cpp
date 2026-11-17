// Problem Statement:
// Problem 15: Write a program to demonstrate runtime polymorphism using virtual functions.

#include <iostream>
#include <vector>

using namespace std;

// Base class
class Animal {
public:
    // Virtual function enables dynamic binding via vtable
    virtual void makeSound() const {
        cout << "[Animal] Generic animal sound." << endl;
    }

    virtual ~Animal() {}
};

// Derived class 1: Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "[Dog] Woof! Woof!" << endl;
    }
};

// Derived class 2: Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "[Cat] Meow! Purr!" << endl;
    }
};

// Derived class 3: Cow
class Cow : public Animal {
public:
    void makeSound() const override {
        cout << "[Cow] Moo! Moo!" << endl;
    }
};

int main() {
    cout << "=== Runtime Polymorphism using Virtual Functions ===" << endl;

    // Base class pointer
    Animal* animalPtr = nullptr;

    Dog myDog;
    Cat myCat;
    Cow myCow;

    cout << "\n1. Base pointer bound to Dog object:" << endl;
    animalPtr = &myDog;
    animalPtr->makeSound(); // Dynamically dispatches Dog::makeSound()

    cout << "\n2. Base pointer bound to Cat object:" << endl;
    animalPtr = &myCat;
    animalPtr->makeSound(); // Dynamically dispatches Cat::makeSound()

    cout << "\n3. Base pointer bound to Cow object:" << endl;
    animalPtr = &myCow;
    animalPtr->makeSound(); // Dynamically dispatches Cow::makeSound()

    cout << "\n4. Polymorphic collection (vector of Animal pointers):" << endl;
    vector<Animal*> barn = { &myDog, &myCat, &myCow };
    for (Animal* a : barn) {
        a->makeSound();
    }

    return 0;
}
