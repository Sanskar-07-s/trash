#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- Part A: Student Array with Average Calculation ---
class StudentReport {
private:
    int rollNo;
    string name;
    float marks1, marks2, marks3;

public:
    // 1. Default constructor
    StudentReport() : rollNo(0), name("Unknown"), marks1(0), marks2(0), marks3(0) {}

    // 2. Parameterized constructor
    StudentReport(int r, string n, float m1, float m2, float m3)
        : rollNo(r), name(n), marks1(m1), marks2(m2), marks3(m3) {}

    void readDetails() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks in 3 subjects: ";
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
             << " | Total: " << calculateTotal() 
             << " | Average: " << calculateAverage() << endl;
    }
};

// --- Part B: Friend Function accessing private members of two classes ---
class ClassB; // Forward declaration

class ClassA {
private:
    int numA;
public:
    ClassA(int val) : numA(val) {}
    friend void findMax(const ClassA& a, const ClassB& b);
};

class ClassB {
private:
    int numB;
public:
    ClassB(int val) : numB(val) {}
    friend void findMax(const ClassA& a, const ClassB& b);
};

void findMax(const ClassA& a, const ClassB& b) {
    cout << "ClassA value: " << a.numA << ", ClassB value: " << b.numB << endl;
    if (a.numA > b.numB) {
        cout << "Larger value is from ClassA: " << a.numA << endl;
    } else if (b.numB > a.numA) {
        cout << "Larger value is from ClassB: " << b.numB << endl;
    } else {
        cout << "Both values are equal." << endl;
    }
}

// --- Part C: Function Overloading - 'add()' for int and float ---
int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

double add(double a, double b, double c) {
    return a + b + c;
}

int main() {
    cout << "========================================================" << endl;
    cout << " EXPERIMENT 3: STUDENT ARRAY, FRIEND FUNCTION & OVERLOAD " << endl;
    cout << "========================================================" << endl;

    // 1. Array of student objects
    int n;
    cout << "Enter number of students (e.g., 2 or 3): ";
    if (!(cin >> n) || n <= 0) n = 2;

    vector<StudentReport> students(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << (i + 1) << ":" << endl;
        students[i].readDetails();
    }

    cout << "\n--- All Student Records ---" << endl;
    int topIndex = 0;
    float maxAvg = students[0].calculateAverage();

    for (int i = 0; i < n; ++i) {
        students[i].display();
        if (students[i].calculateAverage() > maxAvg) {
            maxAvg = students[i].calculateAverage();
            topIndex = i;
        }
    }

    cout << "\n*** Student with the Highest Average ***" << endl;
    students[topIndex].display();

    // 2. Friend function demo
    cout << "\n--- Friend Function Demonstration ---" << endl;
    ClassA objA(125);
    ClassB objB(250);
    findMax(objA, objB);

    // 3. Function Overloading demo
    cout << "\n--- Function Overloading 'add()' Demonstration ---" << endl;
    cout << "add(15, 30)       = " << add(15, 30) << " (int)" << endl;
    cout << "add(12.5f, 4.2f)   = " << add(12.5f, 4.2f) << " (float)" << endl;
    cout << "add(1.1, 2.2, 3.3) = " << add(1.1, 2.2, 3.3) << " (double)" << endl;

    return 0;
}
