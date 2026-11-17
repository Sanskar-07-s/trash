#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default and parameterized constructors
    Complex(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}

    // Overloading '+' operator
    Complex operator+(const Complex& obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Overloading '-' operator
    Complex operator-(const Complex& obj) const {
        return Complex(real - obj.real, imag - obj.imag);
    }

    // Display function
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
};

int main() {
    cout << "========================================" << endl;
    cout << " EXPERIMENT 4: COMPLEX OPERATOR OVERLOAD " << endl;
    cout << "========================================" << endl;

    Complex c1, c2;
    cout << "Enter first complex number (c1):" << endl;
    c1.input();
    cout << "\nEnter second complex number (c2):" << endl;
    c2.input();

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nResults:" << endl;
    cout << "c1        = "; c1.display();
    cout << "c2        = "; c2.display();
    cout << "c1 + c2   = "; sum.display();
    cout << "c1 - c2   = "; diff.display();

    return 0;
}
