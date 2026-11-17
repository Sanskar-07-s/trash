// Problem Statement:
// Problem 24 (b): Write a program to perform Operator Overloading - Overload '+' for Complex numbers.

#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}

    void read() {
        cout << "Enter Real Part: ";
        cin >> real;
        cout << "Enter Imaginary Part: ";
        cin >> imag;
    }

    // Overloading '+' operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    cout << "=== Operator Overloading: Overload '+' for Complex Numbers ===" << endl;

    Complex c1, c2;

    cout << "\nInput First Complex Number (c1):" << endl;
    c1.read();

    cout << "\nInput Second Complex Number (c2):" << endl;
    c2.read();

    // Invokes overloaded operator+
    Complex sum = c1 + c2;

    cout << "\n--- Result ---" << endl;
    cout << "c1      = "; c1.display();
    cout << "c2      = "; c2.display();
    cout << "c1 + c2 = "; sum.display();

    return 0;
}
