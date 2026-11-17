// Problem Statement:
// Problem 21 (a): Write a program to create Abstract class Shape with derived classes Rectangle and Circle implementing area().

#include <iostream>

using namespace std;

// Abstract Base Class
class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;
    virtual void describe() const = 0;

    virtual ~Shape() {}
};

// Derived Class 1: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double area() const override {
        return length * breadth;
    }

    void describe() const override {
        cout << "Shape: Rectangle (Length = " << length << ", Breadth = " << breadth << ")";
    }
};

// Derived Class 2: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.1415926535 * radius * radius;
    }

    void describe() const override {
        cout << "Shape: Circle (Radius = " << radius << ")";
    }
};

int main() {
    cout << "=== Abstract Class Shape: Rectangle and Circle ===" << endl;

    Shape* shapePtr = nullptr;

    Rectangle rect(12.0, 5.0);
    Circle circ(7.0);

    // Dynamic resolution via Base Pointer
    shapePtr = &rect;
    shapePtr->describe();
    cout << " -> Area = " << shapePtr->area() << endl;

    shapePtr = &circ;
    shapePtr->describe();
    cout << " -> Area = " << shapePtr->area() << endl;

    return 0;
}
