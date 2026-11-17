// Problem Statement:
// Problem 2: Implement a program to overload insertion (<<) and extraction (>>) operators.

#include <iostream>

using namespace std;

class CoordinatePoint {
private:
    int x;
    int y;

public:
    CoordinatePoint(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    // Overloading Extraction Operator (>>) for reading object from standard input stream
    friend istream& operator>>(istream& in, CoordinatePoint& point) {
        cout << "Enter X coordinate: ";
        in >> point.x;
        cout << "Enter Y coordinate: ";
        in >> point.y;
        return in;
    }

    // Overloading Insertion Operator (<<) for writing object to standard output stream
    friend ostream& operator<<(ostream& out, const CoordinatePoint& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
};

int main() {
    cout << "=== Stream Insertion (<<) & Extraction (>>) Overloading ===" << endl;

    CoordinatePoint p1, p2(10, 20);

    cout << "\nEnter coordinates for Point p1 using 'cin >> p1':" << endl;
    cin >> p1;

    cout << "\nDisplaying Points using 'cout << point':" << endl;
    cout << "Point p1 = " << p1 << endl;
    cout << "Point p2 = " << p2 << endl;

    return 0;
}
