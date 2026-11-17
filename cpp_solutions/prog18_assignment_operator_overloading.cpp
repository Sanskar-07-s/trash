#include <iostream>

using namespace std;

class NumberSafe {
private:
    int* data; // Pointer to demonstrate deep-copy assignment

public:
    // Default constructor
    NumberSafe() {
        data = new int(0);
    }

    // Parameterized constructor
    NumberSafe(int val) {
        data = new int(val);
    }

    // Copy constructor (Rule of Three)
    NumberSafe(const NumberSafe& other) {
        data = new int(*other.data);
    }

    // Destructor
    ~NumberSafe() {
        delete data;
        data = nullptr;
    }

    // Safe Overloaded Assignment Operator '='
    NumberSafe& operator=(const NumberSafe& other) {
        cout << "[operator= called] Safely copying value " << *other.data << endl;

        // 1. Guard against self-assignment (e.g., n1 = n1)
        if (this == &other) {
            cout << "Self-assignment detected; skipping copy." << endl;
            return *this;
        }

        // 2. Perform deep copy into existing allocated memory
        *data = *(other.data);

        // 3. Return *this to enable chained assignments (e.g., a = b = c)
        return *this;
    }

    void setValue(int val) {
        *data = val;
    }

    void display() const {
        if (data)
            cout << "Value: " << *data << " (Address: " << data << ")" << endl;
        else
            cout << "Value: null" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 18: SAFE ASSIGNMENT OPERATOR (=) OVERLOAD       " << endl;
    cout << "============================================================" << endl;

    NumberSafe num1(100);
    NumberSafe num2(250);
    NumberSafe num3(500);

    cout << "\nInitial states:" << endl;
    cout << "num1: "; num1.display();
    cout << "num2: "; num2.display();
    cout << "num3: "; num3.display();

    // Assignment operation
    cout << "\nPerforming: num1 = num2;" << endl;
    num1 = num2;
    cout << "num1 after assignment: "; num1.display();

    // Verifying deep copy: changing num2 must not change num1
    cout << "\nModifying num2 to 999..." << endl;
    num2.setValue(999);
    cout << "num2 now: "; num2.display();
    cout << "num1 now: "; num1.display(); // Should still be 250!

    // Testing Chained assignment
    cout << "\nTesting Chained Assignment: num1 = num2 = num3;" << endl;
    num1 = num2 = num3;
    cout << "num1: "; num1.display();
    cout << "num2: "; num2.display();

    // Testing Self-assignment
    cout << "\nTesting Self-assignment: num1 = num1;" << endl;
    num1 = num1;

    return 0;
}
