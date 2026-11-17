// Problem Statement:
// Problem 17 (a): Write a program to demonstrate exception handling Division by Zero.

#include <iostream>
#include <stdexcept>

using namespace std;

// Function that performs division and throws exception if denominator is zero
double divideNumbers(double numerator, double denominator) {
    if (denominator == 0.0) {
        throw runtime_error("Division by zero error: denominator cannot be zero!");
    }
    return numerator / denominator;
}

int main() {
    cout << "=== Exception Handling: Division by Zero ===" << endl;

    double num, den;
    cout << "Enter Numerator: ";
    cin >> num;
    cout << "Enter Denominator: ";
    cin >> den;

    try {
        cout << "\nAttempting division: " << num << " / " << den << "..." << endl;
        double result = divideNumbers(num, den);
        cout << "Success: Result = " << result << endl;
    } catch (const runtime_error& ex) {
        cerr << "\n[Exception Caught] " << ex.what() << endl;
        cerr << "Program handled the exception safely without crashing." << endl;
    }

    cout << "\nProgram execution continues normally after try-catch block." << endl;
    return 0;
}
