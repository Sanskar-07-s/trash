// Problem Statement:
// Problem 3: Function Overloading - Overload 'add()' to add integers and floats.

#include <iostream>

using namespace std;

// Overloaded add() for two integers
int add(int a, int b) {
    cout << "[int add(int, int) called] ";
    return a + b;
}

// Overloaded add() for two floats
float add(float a, float b) {
    cout << "[float add(float, float) called] ";
    return a + b;
}

// Overloaded add() for three integers
int add(int a, int b, int c) {
    cout << "[int add(int, int, int) called] ";
    return a + b + c;
}

// Overloaded add() for double values
double add(double a, double b) {
    cout << "[double add(double, double) called] ";
    return a + b;
}

int main() {
    cout << "=== Function Overloading: Overload 'add()' ===" << endl;

    int i1 = 15, i2 = 25;
    cout << i1 << " + " << i2 << " = " << add(i1, i2) << endl;

    float f1 = 12.35f, f2 = 8.65f;
    cout << f1 << " + " << f2 << " = " << add(f1, f2) << endl;

    int x = 10, y = 20, z = 30;
    cout << x << " + " << y << " + " << z << " = " << add(x, y, z) << endl;

    double d1 = 104.56, d2 = 205.44;
    cout << d1 << " + " << d2 << " = " << add(d1, d2) << endl;

    return 0;
}
