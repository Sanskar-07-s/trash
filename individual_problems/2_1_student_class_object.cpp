// Problem Statement:
// Problem 1: Class and Object - Create class Student with rollNo, name, and mark.

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float mark;

public:
    void inputData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> mark;
    }

    void displayData() const {
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Mark        : " << mark << endl;
    }
};

int main() {
    cout << "=== Class and Object Demonstration ===" << endl;
    Student s;
    s.inputData();
    s.displayData();

    return 0;
}
