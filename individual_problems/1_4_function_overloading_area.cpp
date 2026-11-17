// Problem Statement:
// Problem 4: Function Overloading - Calculate area of different shapes using a user-defined function.

#include <iostream>

using namespace std;

// Overloaded function for Circle
double area(double radius) {
    return 3.1415926535 * radius * radius;
}

// Overloaded function for Rectangle
double area(double length, double breadth) {
    return length * breadth;
}

// Overloaded function for Triangle
float area(float base, float height) {
    return 0.5f * base * height;
}

int main() {
    cout << "=== Function Overloading: Area of Different Shapes ===" << endl;

    double radius = 5.0;
    cout << "1. Circle (radius = " << radius << "): Area = " << area(radius) << endl;

    double length = 8.0, breadth = 4.5;
    cout << "2. Rectangle (length = " << length << ", breadth = " << breadth << "): Area = " << area(length, breadth) << endl;

    float base = 6.0f, height = 3.5f;
    cout << "3. Triangle (base = " << base << ", height = " << height << "): Area = " << area(base, height) << endl;

    return 0;
}
