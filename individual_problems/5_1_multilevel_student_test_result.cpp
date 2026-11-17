// Problem Statement:
// Problem 1: Implement a program to create a student class from which to derive test class and from test class derive result class.
// (Class must have attributes, methods and constructors)

#include <iostream>
#include <string>

using namespace std;

// Base class
class Student {
protected:
    int rollNo;
    string name;

public:
    // Constructor
    Student(int r = 0, string n = "") : rollNo(r), name(n) {}

    void displayStudent() const {
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
    }
};

// Intermediate derived class
class Test : public Student {
protected:
    float mark1;
    float mark2;

public:
    // Constructor
    Test(int r, string n, float m1, float m2)
        : Student(r, n), mark1(m1), mark2(m2) {}

    void displayMarks() const {
        cout << "Subject 1 Mark : " << mark1 << endl;
        cout << "Subject 2 Mark : " << mark2 << endl;
    }
};

// Final derived class
class Result : public Test {
private:
    float totalMarks;

public:
    // Constructor
    Result(int r, string n, float m1, float m2)
        : Test(r, n, m1, m2) {
        totalMarks = mark1 + mark2;
    }

    void displayResult() const {
        cout << "\n========================================" << endl;
        cout << "           STUDENT EXAMINATION          " << endl;
        cout << "========================================" << endl;
        displayStudent();
        displayMarks();
        cout << "----------------------------------------" << endl;
        cout << "Total Marks : " << totalMarks << " / 200" << endl;
        cout << "Percentage  : " << (totalMarks / 200.0f) * 100 << "%" << endl;
        cout << "========================================" << endl;
    }
};

int main() {
    cout << "=== Multilevel Inheritance: Student -> Test -> Result ===" << endl;

    int roll;
    string name;
    float m1, m2;

    cout << "Enter Roll Number: ";
    cin >> roll;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Marks in Subject 1 and Subject 2: ";
    cin >> m1 >> m2;

    Result studentRecord(roll, name, m1, m2);
    studentRecord.displayResult();

    return 0;
}
