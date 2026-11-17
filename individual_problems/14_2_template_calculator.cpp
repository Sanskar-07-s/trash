// Problem Statement:
// Problem 2: Template class Calculator performing arithmetic operations.

#include <iostream>

using namespace std;

template <typename T>
class Calculator {
private:
    T val1;
    T val2;

public:
    Calculator(T a, T b) : val1(a), val2(b) {}

    T add() const {
        return val1 + val2;
    }

    T subtract() const {
        return val1 - val2;
    }

    T multiply() const {
        return val1 * val2;
    }

    T divide() const {
        if (val2 == 0) {
            cout << "[Error: Division by zero!] ";
            return 0;
        }
        return val1 / val2;
    }

    void displayAll() const {
        cout << "Operands: " << val1 << " and " << val2 << endl;
        cout << "  Addition       : " << add() << endl;
        cout << "  Subtraction    : " << subtract() << endl;
        cout << "  Multiplication : " << multiply() << endl;
        cout << "  Division       : " << divide() << endl;
    }
};

int main() {
    cout << "=== Generic Template Class: Calculator<T> ===" << endl;

    // 1. Calculator with integer data types
    cout << "\n--- Integer Calculator: Calculator<int> ---" << endl;
    Calculator<int> intCalc(30, 6);
    intCalc.displayAll();

    // 2. Calculator with floating-point data types
    cout << "\n--- Floating Point Calculator: Calculator<double> ---" << endl;
    Calculator<double> doubleCalc(25.5, 4.0);
    doubleCalc.displayAll();

    // 3. Calculator with float data types
    cout << "\n--- Float Calculator: Calculator<float> ---" << endl;
    Calculator<float> floatCalc(18.25f, 2.5f);
    floatCalc.displayAll();

    return 0;
}
