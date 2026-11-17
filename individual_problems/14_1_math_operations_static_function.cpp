// Problem Statement:
// Problem 1: Create a class MathOperations with two normal functions and one static function.
// a) The static function should return the square of a given number.
// b) Demonstrate calling the static function without creating an object.

#include <iostream>

using namespace std;

class MathOperations {
public:
    // Normal member function 1
    double add(double a, double b) const {
        return a + b;
    }

    // Normal member function 2
    double multiply(double a, double b) const {
        return a * b;
    }

    // Static function returning square of a number
    static double square(double num) {
        return num * num;
    }
};

int main() {
    cout << "=== Static Member Function: MathOperations ===" << endl;

    double number = 8.5;

    // Requirement (b): Calling static function WITHOUT creating an object
    cout << "\nCalling static function without object:" << endl;
    cout << "MathOperations::square(" << number << ") = " << MathOperations::square(number) << endl;

    // Calling normal member functions (requires an object instance)
    cout << "\nCalling normal member functions using an object:" << endl;
    MathOperations mathObj;
    cout << "mathObj.add(14.5, 5.5)       = " << mathObj.add(14.5, 5.5) << endl;
    cout << "mathObj.multiply(6.0, 7.0)  = " << mathObj.multiply(6.0, 7.0) << endl;

    return 0;
}
