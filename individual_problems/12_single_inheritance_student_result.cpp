// Problem Statement:
// Problem 12: Write a program to create two classes - Student and Result.
// a) Base class: Student
//    - Data members: rollNo, name
//    - Member function: getDetails() to read details
// b) Derived class: Result
//    - Data members: marks1, marks2, marks3
//    - Member functions:
//      * calculateTotal() - to calculate total marks
//      * displayResult() - to display student details and total marks
// Demonstrate single inheritance by creating an object of Result and displaying the student's total marks.

#include <iostream>
#include <string>

using namespace std;

// Base class
class Student {
protected:
    int rollNo;
    string name;

public:
    void getDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }

    void displayStudentInfo() const {
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
    }
};

// Derived class
class Result : public Student {
private:
    float marks1;
    float marks2;
    float marks3;

public:
    void readMarks() {
        // Read Student info first
        getDetails();
        cout << "Enter marks for Subject 1: ";
        cin >> marks1;
        cout << "Enter marks for Subject 2: ";
        cin >> marks2;
        cout << "Enter marks for Subject 3: ";
        cin >> marks3;
    }

    float calculateTotal() const {
        return marks1 + marks2 + marks3;
    }

    void displayResult() const {
        cout << "\n==============================================" << endl;
        cout << "           STUDENT RESULT SUMMARY             " << endl;
        cout << "==============================================" << endl;
        displayStudentInfo();
        cout << "----------------------------------------------" << endl;
        cout << "Subject 1 Marks : " << marks1 << endl;
        cout << "Subject 2 Marks : " << marks2 << endl;
        cout << "Subject 3 Marks : " << marks3 << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Total Marks     : " << calculateTotal() << " / 300" << endl;
        cout << "Average         : " << (calculateTotal() / 3.0f) << "%" << endl;
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Single Inheritance: Student -> Result ===" << endl;

    Result studentResultObj;
    cout << "Reading student and marks details:" << endl;
    studentResultObj.readMarks();

    studentResultObj.displayResult();

    return 0;
}
