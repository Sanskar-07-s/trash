// Problem Statement:
// Problem 1: Basic Input/Output - Take name and age as input and display a greeting message.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;

    cout << "=== Basic Input/Output Program ===" << endl;
    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "\nHello, " << name << "! You are " << age << " years old." << endl;
    cout << "Welcome to C++ Programming!" << endl;

    return 0;
}
