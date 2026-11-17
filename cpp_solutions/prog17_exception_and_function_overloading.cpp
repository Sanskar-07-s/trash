#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// ====================================================================
// Part A: Exception Handling - Division by Zero
// ====================================================================
double divide(double numerator, double denominator) {
    if (denominator == 0.0) {
        throw runtime_error("Math Error: Division by zero is undefined!");
    }
    return numerator / denominator;
}

// ====================================================================
// Part B: Function Overloading - Area of Different Shapes
// ====================================================================

// Area of Square
double calculateArea(double side) {
    return side * side;
}

// Area of Rectangle
double calculateArea(double length, double breadth) {
    return length * breadth;
}

// Area of Triangle (base and height)
float calculateArea(float base, float height) {
    return 0.5f * base * height;
}

// Area of Circle
double calculateArea(double radius, bool isCircle) {
    if (isCircle) {
        return 3.1415926535 * radius * radius;
    }
    return radius * radius;
}

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 17: EXCEPTION HANDLING & FUNCTION OVERLOADING   " << endl;
    cout << "============================================================" << endl;

    // --- Part A: Division by Zero Exception Handling ---
    cout << "\n--- Part A: Exception Handling (Division by Zero) ---" << endl;
    double a, b;
    double testCases[2][2] = { {20.0, 4.0}, {15.0, 0.0} };

    for (int i = 0; i < 2; ++i) {
        a = testCases[i][0];
        b = testCases[i][1];
        cout << "\nAttempting: " << a << " / " << b << endl;
        try {
            double result = divide(a, b);
            cout << "Result = " << result << endl;
        } catch (const runtime_error& e) {
            cerr << "[Caught Exception]: " << e.what() << endl;
        }
    }

    // --- Part B: Area Calculation via Function Overloading ---
    cout << "\n--- Part B: Function Overloading (Shape Areas) ---" << endl;
    cout << "Area of Square (side = 5.0)       : " << calculateArea(5.0) << endl;
    cout << "Area of Rectangle (8.0 x 4.0)     : " << calculateArea(8.0, 4.0) << endl;
    cout << "Area of Triangle (base 6, ht 3)   : " << calculateArea(6.0f, 3.0f) << endl;
    cout << "Area of Circle (radius = 7.0)     : " << calculateArea(7.0, true) << endl;

    return 0;
}
