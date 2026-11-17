#include <iostream>
#include <string>

using namespace std;

// ====================================================================
// Part A: Abstract Class Shape with Rectangle & Circle
// ====================================================================

class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;
    virtual void printShapeName() const = 0;

    virtual ~Shape() {}
};

class RectangleShape : public Shape {
private:
    double length;
    double breadth;

public:
    RectangleShape(double l, double b) : length(l), breadth(b) {}

    double area() const override {
        return length * breadth;
    }

    void printShapeName() const override {
        cout << "Shape: Rectangle (Length = " << length << ", Breadth = " << breadth << ")";
    }
};

class CircleShape : public Shape {
private:
    double radius;

public:
    CircleShape(double r) : radius(r) {}

    double area() const override {
        return 3.1415926535 * radius * radius;
    }

    void printShapeName() const override {
        cout << "Shape: Circle (Radius = " << radius << ")";
    }
};

// ====================================================================
// Part B: Student Class with Input and Display Member Functions
// ====================================================================

class BasicStudent {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputDetails() {
        cout << "\nEnter Student Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Marks: ";
        cin >> marks;
    }

    void displayDetails() const {
        cout << "\n----------------------------------------" << endl;
        cout << "             STUDENT RECORD             " << endl;
        cout << "----------------------------------------" << endl;
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks       : " << marks << endl;
        cout << "----------------------------------------" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 21: ABSTRACT SHAPE & STUDENT CLASS              " << endl;
    cout << "============================================================" << endl;

    // --- Part A: Abstract Shape and Derived Classes ---
    cout << "\n--- Part A: Abstract Class Shape ---" << endl;
    Shape* shapePtr = nullptr;

    RectangleShape rect(14.0, 6.0);
    CircleShape circ(7.0);

    shapePtr = &rect;
    shapePtr->printShapeName();
    cout << " -> Area = " << shapePtr->area() << endl;

    shapePtr = &circ;
    shapePtr->printShapeName();
    cout << " -> Area = " << shapePtr->area() << endl;

    // --- Part B: Student input and display ---
    cout << "\n--- Part B: Basic Student Class ---" << endl;
    BasicStudent student;
    student.inputDetails();
    student.displayDetails();

    return 0;
}
