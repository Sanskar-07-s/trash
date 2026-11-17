// Problem Statement:
// Problem 20 (a): Write a program to demonstrate Friend Class - Use friend class Calculator to access Rectangle's private data.

#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
    Rectangle(double l = 0.0, double b = 0.0) : length(l), breadth(b) {}

    // Granting friend status to Calculator class
    friend class Calculator;
};

class Calculator {
public:
    // Member function of Calculator accessing private members of Rectangle
    double calculateArea(const Rectangle& rect) const {
        return rect.length * rect.breadth;
    }

    double calculatePerimeter(const Rectangle& rect) const {
        return 2 * (rect.length + rect.breadth);
    }
};

int main() {
    cout << "=== Friend Class: Calculator accessing Rectangle ===" << endl;

    double l, b;
    cout << "Enter Length of Rectangle: ";
    cin >> l;
    cout << "Enter Breadth of Rectangle: ";
    cin >> b;

    Rectangle rect(l, b);
    Calculator calc;

    cout << "\nResults computed via Friend Class 'Calculator':" << endl;
    cout << "Area of Rectangle      = " << calc.calculateArea(rect) << endl;
    cout << "Perimeter of Rectangle = " << calc.calculatePerimeter(rect) << endl;

    return 0;
}
