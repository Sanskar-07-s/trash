#include <iostream>

using namespace std;

void showArithmeticMenu() {
    cout << "\n--- Arithmetic Operations Menu ---" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Modulo (%) [integers only]" << endl;
    cout << "Enter your choice: ";
}

void showRelationalMenu() {
    cout << "\n--- Relational Operations Menu ---" << endl;
    cout << "1. Less Than (<)" << endl;
    cout << "2. Greater Than (>)" << endl;
    cout << "3. Less Than or Equal (<=)" << endl;
    cout << "4. Greater Than or Equal (>=)" << endl;
    cout << "5. Equal to (==)" << endl;
    cout << "6. Not Equal to (!=)" << endl;
    cout << "Enter your choice: ";
}

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 22: MENU-DRIVEN ARITHMETIC & RELATIONAL OPS     " << endl;
    cout << "============================================================" << endl;

    int mainChoice;
    do {
        cout << "\n============ MAIN MENU ============" << endl;
        cout << "1. Arithmetic Operations" << endl;
        cout << "2. Relational Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        if (!(cin >> mainChoice)) break;

        if (mainChoice == 1) {
            double a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            showArithmeticMenu();
            int subChoice;
            cin >> subChoice;

            switch (subChoice) {
                case 1:
                    cout << a << " + " << b << " = " << (a + b) << endl;
                    break;
                case 2:
                    cout << a << " - " << b << " = " << (a - b) << endl;
                    break;
                case 3:
                    cout << a << " * " << b << " = " << (a * b) << endl;
                    break;
                case 4:
                    if (b != 0)
                        cout << a << " / " << b << " = " << (a / b) << endl;
                    else
                        cout << "Error: Division by zero!" << endl;
                    break;
                case 5:
                    if (static_cast<int>(b) != 0)
                        cout << static_cast<int>(a) << " % " << static_cast<int>(b) << " = " 
                             << (static_cast<int>(a) % static_cast<int>(b)) << endl;
                    else
                        cout << "Error: Modulo by zero!" << endl;
                    break;
                default:
                    cout << "Invalid arithmetic choice!" << endl;
            }
        } else if (mainChoice == 2) {
            double a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            showRelationalMenu();
            int subChoice;
            cin >> subChoice;

            cout << boolalpha; // Prints true/false instead of 1/0
            switch (subChoice) {
                case 1:
                    cout << a << " < " << b << " is " << (a < b) << endl;
                    break;
                case 2:
                    cout << a << " > " << b << " is " << (a > b) << endl;
                    break;
                case 3:
                    cout << a << " <= " << b << " is " << (a <= b) << endl;
                    break;
                case 4:
                    cout << a << " >= " << b << " is " << (a >= b) << endl;
                    break;
                case 5:
                    cout << a << " == " << b << " is " << (a == b) << endl;
                    break;
                case 6:
                    cout << a << " != " << b << " is " << (a != b) << endl;
                    break;
                default:
                    cout << "Invalid relational choice!" << endl;
            }
        } else if (mainChoice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            cout << "Invalid menu choice! Please try again." << endl;
        }
    } while (mainChoice != 3);

    return 0;
}
