// Problem Statement:
// Problem 2: Friend Function - Use friend function to access private members of two classes.

#include <iostream>

using namespace std;

// Forward declaration of ClassB
class ClassB;

class ClassA {
private:
    int valueA;

public:
    ClassA(int val) : valueA(val) {}

    // Declaring external friend function
    friend void compareValues(const ClassA& objA, const ClassB& objB);
};

class ClassB {
private:
    int valueB;

public:
    ClassB(int val) : valueB(val) {}

    // Declaring external friend function
    friend void compareValues(const ClassA& objA, const ClassB& objB);
};

// Friend function definition - directly accesses private members valueA and valueB
void compareValues(const ClassA& objA, const ClassB& objB) {
    cout << "ClassA private value: " << objA.valueA << endl;
    cout << "ClassB private value: " << objB.valueB << endl;

    if (objA.valueA > objB.valueB) {
        cout << "ClassA contains the larger value (" << objA.valueA << " > " << objB.valueB << ")." << endl;
    } else if (objB.valueB > objA.valueA) {
        cout << "ClassB contains the larger value (" << objB.valueB << " > " << objA.valueA << ")." << endl;
    } else {
        cout << "Both classes contain equal values (" << objA.valueA << ")." << endl;
    }
}

int main() {
    cout << "=== Friend Function Accessing Two Classes ===" << endl;

    int val1, val2;
    cout << "Enter an integer for ClassA: ";
    cin >> val1;
    cout << "Enter an integer for ClassB: ";
    cin >> val2;

    ClassA a(val1);
    ClassB b(val2);

    cout << "\nInvoking friend function compareValues():" << endl;
    compareValues(a, b);

    return 0;
}
