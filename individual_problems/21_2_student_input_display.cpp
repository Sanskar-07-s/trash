// Problem Statement:
// Problem 21 (b): Implement a program to define a Student class with attributes like name, roll number, and marks. 
// Implement member functions to input and display student details.

#include <iostream>
#include <string>

using namespace std;

class StudentDetails {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputDetails() {
        cout << "Enter Student Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Marks: ";
        cin >> marks;
    }

    void displayDetails() const {
        cout << "\n==============================================" << endl;
        cout << "              STUDENT RECORD CARD             " << endl;
        cout << "==============================================" << endl;
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Full Name   : " << name << endl;
        cout << "Total Marks : " << marks << endl;
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Student Class: Input and Display Functions ===" << endl;

    StudentDetails studentObj;
    cout << "Please enter student details:" << endl;
    studentObj.inputDetails();

    studentObj.displayDetails();

    return 0;
}
