#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Problem 4: Function Overloading for calculating area
double area(double radius) {
    return 3.14159 * radius * radius; // Area of Circle
}

double area(double length, double breadth) {
    return length * breadth; // Area of Rectangle
}

float area(float base, float height) {
    return 0.5f * base * height; // Area of Triangle
}

int main() {
    cout << "========================================" << endl;
    cout << "     EXPERIMENT 1: BASIC CONCEPTS       " << endl;
    cout << "========================================" << endl;

    // --- Problem 1: Basic Input/Output ---
    cout << "\n--- Problem 1: Basic Input/Output ---" << endl;
    string name;
    int age;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Hello, " << name << "! You are " << age << " years old. Welcome to C++ Programming!" << endl;

    // --- Problem 2: Control Structures ---
    cout << "\n--- Problem 2: Control Structures (Grade Calculation) ---" << endl;
    float marks;
    cout << "Enter marks obtained (0 - 100): ";
    cin >> marks;

    if (marks >= 90 && marks <= 100) {
        cout << "Grade: A+ (Outstanding)" << endl;
    } else if (marks >= 80) {
        cout << "Grade: A (Excellent)" << endl;
    } else if (marks >= 70) {
        cout << "Grade: B (Good)" << endl;
    } else if (marks >= 60) {
        cout << "Grade: C (Average)" << endl;
    } else if (marks >= 50) {
        cout << "Grade: D (Pass)" << endl;
    } else if (marks >= 0) {
        cout << "Grade: F (Fail)" << endl;
    } else {
        cout << "Invalid marks entered!" << endl;
    }

    // --- Problem 3: Loop Structures ---
    cout << "\n--- Problem 3: Loop Structures (Factorial) ---" << endl;
    int n;
    long long factorial = 1;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        cout << "Factorial of " << n << " = " << factorial << endl;
    }

    // --- Problem 4: Function Overloading ---
    cout << "\n--- Problem 4: Function Overloading (Area of Shapes) ---" << endl;
    double r = 5.0;
    double l = 10.0, b = 4.0;
    float base = 6.0f, h = 3.0f;

    cout << "Area of Circle (radius = " << r << "): " << area(r) << endl;
    cout << "Area of Rectangle (len = " << l << ", breadth = " << b << "): " << area(l, b) << endl;
    cout << "Area of Triangle (base = " << base << ", height = " << h << "): " << area(base, h) << endl;

    return 0;
}
