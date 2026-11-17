#include <iostream>

using namespace std;

class ComplexNumber {
private:
    float real;
    float imag;

public:
    // Constructors
    ComplexNumber(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}

    void input() {
        cout << "Enter Real Part: ";
        cin >> real;
        cout << "Enter Imaginary Part: ";
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
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 19: COMPLEX CLASS WITH MEMBER FUNCTIONS         " << endl;
    cout << "============================================================" << endl;

    ComplexNumber c1(5.5f, 3.2f);
    ComplexNumber c2(2.1f, -1.4f);

    cout << "\nComplex Number 1: ";
    c1.display();

    cout << "Complex Number 2: ";
    c2.display();

    // Calling member functions
    ComplexNumber sum = c1.add(c2);
    ComplexNumber diff = c1.subtract(c2);

    cout << "\nSum (c1.add(c2))        : ";
    sum.display();

    cout << "Difference (c1.sub(c2)) : ";
    diff.display();

    return 0;
}
