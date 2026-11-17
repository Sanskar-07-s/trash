// Problem Statement:
// Problem 2: Define a Student class with attributes like name, roll number, and marks.
// Implement constructor, destructor, member functions (input and display student details).
// Demonstrate manual (heap) and automatic (stack) object creation and destruction.

#include <iostream>
#include <string>

using namespace std;

class StudentLifecycle {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Default Constructor
    StudentLifecycle() : name("Anonymous"), rollNumber(0), marks(0.0f) {
        cout << "[Constructor] Default Student object created." << endl;
    }

    // Parameterized Constructor
    StudentLifecycle(string n, int r, float m) : name(n), rollNumber(r), marks(m) {
        cout << "[Constructor] Student \"" << name << "\" (Roll: " << rollNumber << ") created." << endl;
    }

    // Destructor
    ~StudentLifecycle() {
        cout << "[Destructor] Student \"" << name << "\" (Roll: " << rollNumber << ") destroyed." << endl;
    }

    void input() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Student -> Roll: " << rollNumber << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    cout << "=== Object Lifecycle: Automatic (Stack) vs Manual (Heap) ===" << endl;

    // 1. Automatic Object Creation (Stack Allocation)
    cout << "\n--- 1. Automatic Object Creation (Stack Scope) ---" << endl;
    {
        cout << "Entering inner block scope..." << endl;
        StudentLifecycle autoStudent("Bruce Wayne", 100, 95.5f);
        autoStudent.display();
        cout << "Exiting inner block scope..." << endl;
    } // autoStudent automatically destroyed when scope ends

    // 2. Manual Object Creation (Heap Allocation using 'new' and 'delete')
    cout << "\n--- 2. Manual Object Creation (Heap with new / delete) ---" << endl;
    cout << "Allocating object dynamically with 'new'..." << endl;
    StudentLifecycle* heapStudent = new StudentLifecycle("Clark Kent", 101, 98.0f);
    heapStudent->display();

    cout << "\nExplicitly freeing heap memory using 'delete'..." << endl;
    delete heapStudent; // Calls destructor manually
    heapStudent = nullptr;

    cout << "\nProgram execution finished." << endl;
    return 0;
}
