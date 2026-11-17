// Problem Statement:
// Problem 18: Write a program to create a class 'number' that overloads the assignment operator '=' 
// to copy one number object to another safely.

#include <iostream>

using namespace std;

class NumberSafeCopy {
private:
    int* ptr; // Dynamically allocated data member to demonstrate deep copy

public:
    // Parameterized Constructor
    NumberSafeCopy(int val = 0) {
        ptr = new int(val);
        cout << "[Constructor] Allocated integer with value " << *ptr << endl;
    }

    // Copy Constructor (Rule of Three)
    NumberSafeCopy(const NumberSafeCopy& other) {
        ptr = new int(*other.ptr);
        cout << "[Copy Constructor] Deep-copied value " << *ptr << endl;
    }

    // Overloaded Assignment Operator '=' for safe assignment
    NumberSafeCopy& operator=(const NumberSafeCopy& other) {
        cout << "[operator= called] Safe assignment invoked." << endl;

        // 1. Guard against self-assignment (e.g., obj = obj)
        if (this == &other) {
            cout << "  -> Self-assignment detected; skipping copy operation." << endl;
            return *this;
        }

        // 2. Perform deep copy into existing allocated memory
        *ptr = *(other.ptr);

        // 3. Return *this to allow chained assignments (e.g., a = b = c)
        return *this;
    }

    // Destructor
    ~NumberSafeCopy() {
        if (ptr) {
            cout << "[Destructor] Deallocated value " << *ptr << endl;
            delete ptr;
            ptr = nullptr;
        }
    }

    void setValue(int val) {
        *ptr = val;
    }

    void display() const {
        if (ptr)
            cout << "Value = " << *ptr << " (Pointer Address: " << ptr << ")" << endl;
    }
};

int main() {
    cout << "=== Safe Assignment Operator (=) Overloading ===" << endl;

    NumberSafeCopy num1(50);
    NumberSafeCopy num2(120);
    NumberSafeCopy num3(200);

    cout << "\nInitial Object Values:" << endl;
    cout << "num1: "; num1.display();
    cout << "num2: "; num2.display();
    cout << "num3: "; num3.display();

    cout << "\nExecuting: num1 = num2;" << endl;
    num1 = num2; // Calls operator=
    cout << "num1 after assignment: "; num1.display();

    cout << "\nModifying num2 to 999 to test deep copy isolation..." << endl;
    num2.setValue(999);
    cout << "num2 after modification: "; num2.display();
    cout << "num1 remains unchanged : "; num1.display(); // num1 remains 120!

    cout << "\nTesting Chained Assignment: num1 = num2 = num3;" << endl;
    num1 = num2 = num3;
    cout << "num1: "; num1.display();
    cout << "num2: "; num2.display();

    cout << "\nTesting Self-Assignment: num1 = num1;" << endl;
    num1 = num1;

    return 0;
}
