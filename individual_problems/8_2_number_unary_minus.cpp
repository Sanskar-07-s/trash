// Problem Statement:
// Problem 2: Create a class 'Number' with a private integer member. 
// Overload the unary '-' operator to change the sign of the number.

#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    // Overload unary '-' operator
    Number operator-() const {
        return Number(-value);
    }

    void setValue(int v) {
        value = v;
    }

    void display() const {
        cout << "Value = " << value << endl;
    }
};

int main() {
    cout << "=== Unary Operator Overloading: Sign Change (-) ===" << endl;

    Number n1(75);
    Number n2(-34);

    cout << "Original n1: ";
    n1.display();

    Number negatedN1 = -n1; // Invokes operator-()
    cout << "Negated n1 (-n1): ";
    negatedN1.display();

    cout << "\nOriginal n2: ";
    n2.display();

    Number negatedN2 = -n2; // Invokes operator-()
    cout << "Negated n2 (-n2): ";
    negatedN2.display();

    return 0;
}
