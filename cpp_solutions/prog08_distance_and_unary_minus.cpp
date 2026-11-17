#include <iostream>
#include <cmath>

using namespace std;

// ====================================================================
// Part 1: Distance Class - Overload Binary '-' Operator
// ====================================================================

class Distance {
private:
    int feet;
    float inches;

public:
    Distance(int f = 0, float in = 0.0f) : feet(f), inches(in) {
        normalize();
    }

    void normalize() {
        if (inches >= 12.0f) {
            feet += static_cast<int>(inches) / 12;
            inches = fmod(inches, 12.0f);
        }
    }

    // Overloading '-' operator
    Distance operator-(const Distance& d) const {
        // Convert both distances to total inches
        float totalInches1 = (feet * 12.0f) + inches;
        float totalInches2 = (d.feet * 12.0f) + d.inches;
        float diffInches = abs(totalInches1 - totalInches2);

        int resFeet = static_cast<int>(diffInches) / 12;
        float resInches = fmod(diffInches, 12.0f);

        return Distance(resFeet, resInches);
    }

    void display() const {
        cout << feet << " feet, " << inches << " inches" << endl;
    }
};

// ====================================================================
// Part 2: Number Class - Overload Unary '-' Operator
// ====================================================================

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    // Overloading unary '-' operator (returns a new negated Number object)
    Number operator-() const {
        return Number(-value);
    }

    void display() const {
        cout << "Number value: " << value << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 8: DISTANCE '-' AND UNARY '-' OPERATOR OVERLOAD " << endl;
    cout << "============================================================" << endl;

    // Part 1: Distance difference
    cout << "\n--- Distance Difference (Binary -) ---" << endl;
    Distance d1(8, 6.5f);
    Distance d2(3, 10.0f);

    cout << "Distance 1: "; d1.display();
    cout << "Distance 2: "; d2.display();

    Distance diff = d1 - d2;
    cout << "Difference (d1 - d2): "; diff.display();

    // Part 2: Unary minus
    cout << "\n--- Unary '-' Operator Overload ---" << endl;
    Number n1(42);
    Number n2(-17);

    cout << "Original n1: "; n1.display();
    Number negated1 = -n1;
    cout << "Negated (-n1): "; negated1.display();

    cout << "Original n2: "; n2.display();
    Number negated2 = -n2;
    cout << "Negated (-n2): "; negated2.display();

    return 0;
}
