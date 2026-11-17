#include <iostream>
#include <string>

using namespace std;

// Base class: Student
class Student {
protected:
    int rollNo;
    string name;

public:
    void getDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void displayDetails() const {
        cout << "Roll Number : " << rollNo << endl;
        cout << "Student Name: " << name << endl;
    }
};

// Derived class: Result
class Result : public Student {
private:
    float marks1;
    float marks2;
    float marks3;

public:
    void getMarks() {
        // Read base student details first
        getDetails();
        cout << "Enter Marks in Subject 1: ";
        cin >> marks1;
        cout << "Enter Marks in Subject 2: ";
        cin >> marks2;
        cout << "Enter Marks in Subject 3: ";
        cin >> marks3;
    }

    float calculateTotal() const {
        return marks1 + marks2 + marks3;
    }

    void displayResult() const {
        cout << "\n========================================" << endl;
        cout << "           STUDENT RESULT CARD          " << endl;
        cout << "========================================" << endl;
        displayDetails();
        cout << "Marks: Subject 1 = " << marks1 
             << ", Subject 2 = " << marks2 
             << ", Subject 3 = " << marks3 << endl;
        cout << "----------------------------------------" << endl;
        cout << "Total Marks : " << calculateTotal() << " / 300" << endl;
        cout << "========================================" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 12: SINGLE INHERITANCE (STUDENT -> RESULT)      " << endl;
    cout << "============================================================" << endl;

    Result studentResult;
    cout << "Enter Student Examination Details:" << endl;
    studentResult.getMarks();

    studentResult.displayResult();

    return 0;
}
