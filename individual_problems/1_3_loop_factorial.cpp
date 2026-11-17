// Problem Statement:
// Problem 3: Loop Structures - Print factorial of a number using a for loop.

#include <iostream>

using namespace std;

int main() {
    int num;
    unsigned long long factorial = 1;

    cout << "=== Loop Structures: Factorial Calculation ===" << endl;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is undefined for negative numbers." << endl;
    } else {
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        cout << "The factorial of " << num << " (" << num << "!) is: " << factorial << endl;
    }

    return 0;
}
