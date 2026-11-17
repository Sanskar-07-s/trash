// Problem Statement:
// Problem 16: Create a class Student having roll number and name. 
// Inside it, define a nested class Address with city and state. 
// Create an object of a nested class through Student and display both Student and Address information.

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;

public:
    // Nested Class: Address
    class Address {
    private:
        string city;
        string state;

    public:
        Address(string c = "", string s = "") : city(c), state(s) {}

        void inputAddress() {
            cout << "Enter City: ";
            getline(cin, city);
            cout << "Enter State: ";
            getline(cin, state);
        }

        void displayAddress() const {
            cout << "City        : " << city << endl;
            cout << "State       : " << state << endl;
        }
    };

private:
    Address studentAddress; // Nested object embedded inside Student

public:
    Student(int roll, string n, string city, string state)
        : rollNumber(roll), name(n), studentAddress(city, state) {}

    void displayFullInfo() const {
        cout << "\n==============================================" << endl;
        cout << "       STUDENT & RESIDENTIAL ADDRESS          " << endl;
        cout << "==============================================" << endl;
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name        : " << name << endl;
        studentAddress.displayAddress();
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Nested Class Demonstration (Student & Address) ===" << endl;

    // Creating Student object with Address
    Student s1(101, "Alice Cooper", "Chicago", "Illinois");
    s1.displayFullInfo();

    // Demonstrating direct instantiation of nested class Address through Student's scope
    cout << "\nInstantiating nested class Address independently via Student::Address:" << endl;
    Student::Address standaloneAddr("Mumbai", "Maharashtra");
    standaloneAddr.displayAddress();

    return 0;
}
