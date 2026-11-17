// Problem Statement:
// Problem 1: Create an array of student objects, read details for n students, and display the student with the highest average.
// Data members: rollNo, name, marks1, marks2, marks3
// Requirements:
// 1. Default constructor
// 2. Parameterized constructor to initialize all members
// 3. calculateTotal() - returns total marks
// 4. calculateAverage() - returns average marks
// 5. display() - displays student details and results

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentRecord {
private:
    int rollNo;
    string name;
    float marks1;
    float marks2;
    float marks3;

public:
    // 1. Default constructor
    StudentRecord() : rollNo(0), name("Unknown"), marks1(0.0f), marks2(0.0f), marks3(0.0f) {}

    // 2. Parameterized constructor
    StudentRecord(int r, string n, float m1, float m2, float m3)
        : rollNo(r), name(n), marks1(m1), marks2(m2), marks3(m3) {}

    void readDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks in 3 subjects (out of 100): ";
        cin >> marks1 >> marks2 >> marks3;
    }

    // 3. calculateTotal()
    float calculateTotal() const {
        return marks1 + marks2 + marks3;
    }

    // 4. calculateAverage()
    float calculateAverage() const {
        return calculateTotal() / 3.0f;
    }

    // 5. display()
    void display() const {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Marks: [" << marks1 << ", " << marks2 << ", " << marks3 << "]"
             << " | Total: " << calculateTotal()
             << " | Average: " << calculateAverage() << endl;
    }
};

int main() {
    cout << "=== Array of Student Objects & Highest Average ===" << endl;
    int n;
    cout << "Enter the number of students: ";
    if (!(cin >> n) || n <= 0) {
        n = 2;
    }

    vector<StudentRecord> students(n);

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Enter details for Student " << (i + 1) << " ---" << endl;
        students[i].readDetails();
    }

    cout << "\n=== All Student Records ===" << endl;
    int highestIndex = 0;
    float highestAverage = students[0].calculateAverage();

    for (int i = 0; i < n; ++i) {
        students[i].display();
        if (students[i].calculateAverage() > highestAverage) {
            highestAverage = students[i].calculateAverage();
            highestIndex = i;
        }
    }

    cout << "\n==============================================" << endl;
    cout << "   STUDENT WITH THE HIGHEST AVERAGE MARKS     " << endl;
    cout << "==============================================" << endl;
    students[highestIndex].display();

    return 0;
}
