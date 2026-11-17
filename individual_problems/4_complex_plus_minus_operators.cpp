// Problem Statement:
// Problem 4: Create a class 'Complex' to represent complex numbers. Overload the '+' and '-' operators to add and subtract two complex numbers.

#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}

    void read() {
        cout << "Enter Real part: ";
        cin >> real;
        cout << "Enter Imaginary part: ";
        cin >> imag;
    }

    // Overloading '+' operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading '-' operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    cout << "=== Operator Overloading: Complex Addition and Subtraction ===" << endl;

    Complex c1, c2;
    cout << "\nInput for First Complex Number (c1):" << endl;
    c1.read();

    cout << "\nInput for Second Complex Number (c2):" << endl;
    c2.read();

    Complex sum = c1 + c2;   // calls c1.operator+(c2)
    Complex diff = c1 - c2;  // calls c1.operator-(c2)

    cout << "\n--- Calculation Results ---" << endl;
    cout << "c1        = "; c1.display();
    cout << "c2        = "; c2.display();
    cout << "c1 + c2   = "; sum.display();
    cout << "c1 - c2   = "; diff.display();

    return 0;
}
