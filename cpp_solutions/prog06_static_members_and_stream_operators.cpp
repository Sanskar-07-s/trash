#include <iostream>
#include <string>

using namespace std;

// ====================================================================
// Problem 1: Static Data Member and Static Member Function Access
// ====================================================================

class Counter {
private:
    int id;
    static int objectCount; // Static data member declaration

public:
    Counter() {
        objectCount++;
        id = objectCount;
        cout << "Object with ID " << id << " created." << endl;
    }

    ~Counter() {
        cout << "Object with ID " << id << " destroyed." << endl;
        objectCount--;
    }

    void showId() const {
        cout << "Instance ID: " << id << endl;
    }

    // Static member function
    static int getCount() {
        // Can only access static members directly
        return objectCount;
    }
};

// Definition and initialization of static data member
int Counter::objectCount = 0;

// ====================================================================
// Problem 2: Overloading Insertion (<<) and Extraction (>>) Operators
// ====================================================================

class Point {
private:
    int x, y;

public:
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    // Overloading >> (Extraction operator)
    friend istream& operator>>(istream& in, Point& p) {
        cout << "Enter X coordinate: ";
        in >> p.x;
        cout << "Enter Y coordinate: ";
        in >> p.y;
        return in;
    }

    // Overloading << (Insertion operator)
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 6: STATIC MEMBERS & STREAM OPERATORS OVERLOAD   " << endl;
    cout << "============================================================" << endl;

    // --- Problem 1: Static Member Access ---
    cout << "\n--- Problem 1: Static Members ---" << endl;
    cout << "Initial Object Count (accessed via class name): " << Counter::getCount() << endl;

    Counter c1;
    Counter c2;
    cout << "Count after creating 2 objects: " << Counter::getCount() << endl;

    {
        Counter c3;
        cout << "Count inside block with 3rd object: " << Counter::getCount() << endl;
    }
    cout << "Count after block exit: " << Counter::getCount() << endl;

    // --- Problem 2: Insertion and Extraction Operators ---
    cout << "\n--- Problem 2: Stream Operators Overloading ---" << endl;
    Point p1;
    cout << "Input coordinates for Point p1:" << endl;
    cin >> p1;

    Point p2(15, 25);
    cout << "\nDisplaying points using overloaded << operator:" << endl;
    cout << "Point p1: " << p1 << endl;
    cout << "Point p2: " << p2 << endl;

    return 0;
}
