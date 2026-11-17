// Problem Statement:
// Problem 22: Write a program to perform all arithmetic and relational operations using menu driven.

#include <iostream>

using namespace std;

void printMenu() {
    cout << "\n=================== MENU ===================" << endl;
    cout << "  1. Addition (+)" << endl;
    cout << "  2. Subtraction (-)" << endl;
    cout << "  3. Multiplication (*)" << endl;
    cout << "  4. Division (/)" << endl;
    cout << "  5. Modulo (%) [Integer operands]" << endl;
    cout << "  6. Less Than (<)" << endl;
    cout << "  7. Greater Than (>)" << endl;
    cout << "  8. Less Than or Equal (<=)" << endl;
    cout << "  9. Greater Than or Equal (>=)" << endl;
    cout << " 10. Equal To (==)" << endl;
    cout << " 11. Not Equal To (!=)" << endl;
    cout << " 12. Exit Program" << endl;
    cout << "============================================" << endl;
    cout << "Enter your choice (1-12): ";
}

int main() {
    cout << "=== Menu-Driven Arithmetic & Relational Operations ===" << endl;

    int choice;
    double a, b;

    do {
        printMenu();
        if (!(cin >> choice)) {
            break;
        }

        if (choice >= 1 && choice <= 11) {
            cout << "Enter two numbers (a and b): ";
            cin >> a >> b;
        }

        cout << boolalpha; // Format booleans as 'true' or 'false'
        switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << (a + b) << endl;
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << (a - b) << endl;
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << (a * b) << endl;
                break;
            case 4:
                if (b != 0)
                    cout << "Result: " << a << " / " << b << " = " << (a / b) << endl;
                else
                    cout << "Error: Division by zero is undefined!" << endl;
                break;
            case 5:
                if (static_cast<int>(b) != 0)
                    cout << "Result: " << static_cast<int>(a) << " % " << static_cast<int>(b) 
                         << " = " << (static_cast<int>(a) % static_cast<int>(b)) << endl;
                else
                    cout << "Error: Modulo by zero is undefined!" << endl;
                break;
            case 6:
                cout << "Result: " << a << " < " << b << " is " << (a < b) << endl;
                break;
            case 7:
                cout << "Result: " << a << " > " << b << " is " << (a > b) << endl;
                break;
            case 8:
                cout << "Result: " << a << " <= " << b << " is " << (a <= b) << endl;
                break;
            case 9:
                cout << "Result: " << a << " >= " << b << " is " << (a >= b) << endl;
                break;
            case 10:
                cout << "Result: " << a << " == " << b << " is " << (a == b) << endl;
                break;
            case 11:
                cout << "Result: " << a << " != " << b << " is " << (a != b) << endl;
                break;
            case 12:
                cout << "Exiting menu. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select an option between 1 and 12." << endl;
        }
    } while (choice != 12);

    return 0;
}
