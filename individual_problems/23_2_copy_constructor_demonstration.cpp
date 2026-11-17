// Problem Statement:
// Problem 23 (b): Write a program to perform Copy Constructor - Demonstrate object copying.

#include <iostream>
#include <string>

using namespace std;

class Laptop {
private:
    string manufacturer;
    string modelName;
    double price;

public:
    // Parameterized Constructor
    Laptop(string mfg, string model, double p)
        : manufacturer(mfg), modelName(model), price(p) {
        cout << "[Parameterized Constructor] Created Laptop " << manufacturer << " " << modelName << endl;
    }

    // Explicit Copy Constructor: ClassName(const ClassName& source)
    Laptop(const Laptop& source) {
        manufacturer = source.manufacturer;
        modelName = source.modelName + " (Cloned Replica)";
        price = source.price;
        cout << "[Copy Constructor] Copied Laptop object from source (" 
             << source.manufacturer << " " << source.modelName << ")" << endl;
    }

    void display() const {
        cout << "Device: " << manufacturer << " " << modelName << " | Price: Rs. " << price << endl;
    }
};

int main() {
    cout << "=== Copy Constructor: Object Copying Demonstration ===" << endl;

    // 1. Initializing original object
    cout << "\nCreating original object:" << endl;
    Laptop originalLap("Apple", "MacBook Pro M3", 199900.0);
    cout << "Original Details: ";
    originalLap.display();

    // 2. Invoking copy constructor using initialization syntax: Obj2 = Obj1
    cout << "\nCreating lapCopy1 using initialization syntax (Laptop lapCopy1 = originalLap):" << endl;
    Laptop lapCopy1 = originalLap;
    cout << "lapCopy1 Details: ";
    lapCopy1.display();

    // 3. Invoking copy constructor using constructor call syntax: Obj3(Obj1)
    cout << "\nCreating lapCopy2 using constructor call syntax (Laptop lapCopy2(originalLap)):" << endl;
    Laptop lapCopy2(originalLap);
    cout << "lapCopy2 Details: ";
    lapCopy2.display();

    return 0;
}
