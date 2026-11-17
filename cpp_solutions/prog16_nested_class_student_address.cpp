#include <iostream>
#include <string>

using namespace std;

class StudentWithAddress {
private:
    int rollNo;
    string name;

public:
    // Nested class Address
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
            cout << "City    : " << city << endl;
            cout << "State   : " << state << endl;
        }
    };

private:
    Address addr; // Composition: Address instance inside Student

public:
    StudentWithAddress(int r, string n, string c, string s)
        : rollNo(r), name(n), addr(c, s) {}

    void display() const {
        cout << "\n========================================" << endl;
        cout << "       STUDENT & ADDRESS DETAILS        " << endl;
        cout << "========================================" << endl;
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        addr.displayAddress();
        cout << "========================================" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 16: NESTED CLASS (STUDENT WITH ADDRESS)         " << endl;
    cout << "============================================================" << endl;

    // Creating Student object which holds the nested Address object
    StudentWithAddress s1(101, "Sanskrit Sharma", "Jaipur", "Rajasthan");
    s1.display();

    // Directly instantiating the nested class using the scope resolution operator Outer::Inner
    cout << "\nDirectly creating an independent instance of nested class Address:" << endl;
    StudentWithAddress::Address standaloneAddress("Bengaluru", "Karnataka");
    standaloneAddress.displayAddress();

    return 0;
}
