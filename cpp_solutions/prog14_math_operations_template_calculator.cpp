#include <iostream>

using namespace std;

// ====================================================================
// Part 1: MathOperations Class with Static and Non-static Functions
// ====================================================================

class MathOperations {
public:
    // Normal member function 1
    double add(double a, double b) const {
        return a + b;
    }

    // Normal member function 2
    double multiply(double a, double b) const {
        return a * b;
    }

    // Static function: returns square of a given number
    static double square(double num) {
        return num * num;
    }
};

// ====================================================================
// Part 2: Generic Template Class Calculator
// ====================================================================

template <typename T>
class Calculator {
private:
    T num1;
    T num2;

public:
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}

    T add() const {
        return num1 + num2;
    }

    T subtract() const {
        return num1 - num2;
    }

    T multiply() const {
        return num1 * num2;
    }

    T divide() const {
        if (num2 == 0) {
            cout << "Warning: Division by zero!" << endl;
            return 0;
        }
        return num1 / num2;
    }

    void displayResults() const {
        cout << "Numbers: " << num1 << " and " << num2 << endl;
        cout << "  Addition       : " << add() << endl;
        cout << "  Subtraction    : " << subtract() << endl;
        cout << "  Multiplication : " << multiply() << endl;
        cout << "  Division       : " << divide() << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 14: STATIC FUNCTIONS & TEMPLATE CALCULATOR      " << endl;
    cout << "============================================================" << endl;

    // --- Part 1: MathOperations Demo ---
    cout << "\n--- Part 1: Static Function Calling Without Object ---" << endl;
    double val = 12.5;
    // Calling static function using ClassName::FunctionName
    cout << "Square of " << val << " using MathOperations::square() = " 
         << MathOperations::square(val) << endl;

    cout << "\nNormal functions (require an object instance):" << endl;
    MathOperations mathObj;
    cout << "Add (4.5, 7.5) via object: " << mathObj.add(4.5, 7.5) << endl;
    cout << "Multiply (6.0, 3.5) via object: " << mathObj.multiply(6.0, 3.5) << endl;

    // --- Part 2: Template Class Calculator Demo ---
    cout << "\n--- Part 2: Template Calculator with Integer Types ---" << endl;
    Calculator<int> intCalc(40, 8);
    intCalc.displayResults();

    cout << "\n--- Template Calculator with Floating-point Types ---" << endl;
    Calculator<double> doubleCalc(15.5, 2.5);
    doubleCalc.displayResults();

    return 0;
}
