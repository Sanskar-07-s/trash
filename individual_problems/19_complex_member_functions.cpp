// Problem Statement:
// Problem 19: Implement a program to create a Complex class to represent complex numbers. 
// Implement member functions for addition, subtraction, and display of complex numbers.

#include <iostream>

using namespace std;

class ComplexNumber {
private:
    float real;
    float imag;

public:
    ComplexNumber(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}

    void input() {
        cout << "Enter Real part: ";
        cin >> real;
        cout << "Enter Imaginary part: ";
        cin >> imag;
    }

    // Member function for addition
    ComplexNumber add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Member function for subtraction
    ComplexNumber subtract(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Member function for display
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    cout << "=== Complex Class with Member Functions (add, subtract, display) ===" << endl;

    ComplexNumber c1, c2;

    cout << "\nEnter First Complex Number:" << endl;
    c1.input();

    cout << "\nEnter Second Complex Number:" << endl;
    c2.input();

    ComplexNumber sum = c1.add(c2);
    ComplexNumber diff = c1.subtract(c2);

    cout << "\n--- Output ---" << endl;
    cout << "First Number (c1)       : "; c1.display();
    cout << "Second Number (c2)      : "; c2.display();
    cout << "Sum (c1.add(c2))        : "; sum.display();
    cout << "Difference (c1.sub(c2)) : "; diff.display();

    return 0;
}
