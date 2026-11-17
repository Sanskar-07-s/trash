// Problem Statement:
// Problem 2: Control Structures - Display grade based on marks using if-else.

#include <iostream>

using namespace std;

int main() {
    float marks;

    cout << "=== Control Structures: Grade Evaluation ===" << endl;
    cout << "Enter student marks (0 to 100): ";
    cin >> marks;

    if (marks < 0 || marks > 100) {
        cout << "Invalid marks! Please enter a value between 0 and 100." << endl;
    } else if (marks >= 90) {
        cout << "Grade: A+ (Outstanding Performance)" << endl;
    } else if (marks >= 80) {
        cout << "Grade: A (Excellent Performance)" << endl;
    } else if (marks >= 70) {
        cout << "Grade: B (Good Performance)" << endl;
    } else if (marks >= 60) {
        cout << "Grade: C (Average Performance)" << endl;
    } else if (marks >= 50) {
        cout << "Grade: D (Pass)" << endl;
    } else {
        cout << "Grade: F (Fail - Needs Improvement)" << endl;
    }

    return 0;
}
