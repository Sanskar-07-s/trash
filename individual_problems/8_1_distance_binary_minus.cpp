// Problem Statement:
// Problem 1: Create a class 'Distance' with data members 'feet' and 'inches'. 
// Overload the '-' operator to find the difference between two distances.

#include <iostream>
#include <cmath>

using namespace std;

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

    // Overloading '-' operator to compute absolute difference between two distances
    Distance operator-(const Distance& d) const {
        float totalInches1 = (feet * 12.0f) + inches;
        float totalInches2 = (d.feet * 12.0f) + d.inches;
        float diffInches = abs(totalInches1 - totalInches2);

        int resFeet = static_cast<int>(diffInches) / 12;
        float resInches = fmod(diffInches, 12.0f);

        return Distance(resFeet, resInches);
    }

    void input() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        normalize();
    }

    void display() const {
        cout << feet << " ft " << inches << " in" << endl;
    }
};

int main() {
    cout << "=== Operator Overloading: Distance Difference (-) ===" << endl;

    Distance d1(9, 4.5f);
    Distance d2(4, 9.0f);

    cout << "Distance 1: ";
    d1.display();

    cout << "Distance 2: ";
    d2.display();

    Distance difference = d1 - d2;

    cout << "\nDifference (d1 - d2): ";
    difference.display();

    return 0;
}
