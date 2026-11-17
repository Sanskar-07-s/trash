// Problem Statement:
// Problem 17 (b): Implement a Program to find out area of different shapes using function overloading.

#include <iostream>

using namespace std;

// Area of Square
double findArea(double side) {
    return side * side;
}

// Area of Rectangle
double findArea(double length, double breadth) {
    return length * breadth;
}

// Area of Triangle (base and height)
float findArea(float base, float height) {
    return 0.5f * base * height;
}

// Area of Circle
double findArea(double radius, bool isCircle) {
    if (isCircle) {
        return 3.1415926535 * radius * radius;
    }
    return radius * radius;
}

int main() {
    cout << "=== Function Overloading: Area of Different Shapes ===" << endl;

    double sqSide = 6.0;
    cout << "1. Square    (side = " << sqSide << ")            : Area = " << findArea(sqSide) << endl;

    double rectLen = 10.0, rectBreadth = 4.5;
    cout << "2. Rectangle (len = " << rectLen << ", breadth = " << rectBreadth << ") : Area = " << findArea(rectLen, rectBreadth) << endl;

    float triBase = 7.0f, triHeight = 4.0f;
    cout << "3. Triangle  (base = " << triBase << ", height = " << triHeight << ")   : Area = " << findArea(triBase, triHeight) << endl;

    double circRadius = 7.0;
    cout << "4. Circle    (radius = " << circRadius << ")          : Area = " << findArea(circRadius, true) << endl;

    return 0;
}
