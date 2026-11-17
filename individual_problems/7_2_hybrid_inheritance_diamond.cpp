// Problem Statement:
// Problem 2: Implement a program to perform Hybrid Inheritance.
// (Class must have attributes, methods and constructors)
//
//               Person (Virtual Base)
//              /      \
//          Student   Employee
//              \      /
//           TeachingAssistant

#include <iostream>
#include <string>

using namespace std;

// Virtual Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << endl;
    }
};

// Intermediate Derived Class 1 (Virtual Inheritance)
class Student : virtual public Person {
protected:
    int studentRoll;

public:
    Student(string n, int a, int roll)
        : Person(n, a), studentRoll(roll) {}

    void displayStudent() const {
        cout << "Student Roll: " << studentRoll << endl;
    }
};

// Intermediate Derived Class 2 (Virtual Inheritance)
class Employee : virtual public Person {
protected:
    int employeeId;
    double stipend;

public:
    Employee(string n, int a, int empId, double s)
        : Person(n, a), employeeId(empId), stipend(s) {}

    void displayEmployee() const {
        cout << "Employee ID : " << employeeId << endl;
        cout << "Stipend     : Rs. " << stipend << endl;
    }
};

// Final Derived Class: TeachingAssistant (Hybrid Inheritance)
class TeachingAssistant : public Student, public Employee {
private:
    string courseAssigned;

public:
    // In virtual inheritance, the most-derived class calls the virtual base class constructor
    TeachingAssistant(string n, int a, int roll, int empId, double s, string course)
        : Person(n, a), Student(n, a, roll), Employee(n, a, empId, s), courseAssigned(course) {}

    void displayProfile() const {
        cout << "\n==============================================" << endl;
        cout << "        TEACHING ASSISTANT (HYBRID)           " << endl;
        cout << "==============================================" << endl;
        displayPerson();    // Single unambiguous call because Person is virtual base
        displayStudent();
        displayEmployee();
        cout << "Assigned Lab: " << courseAssigned << endl;
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Hybrid Inheritance with Virtual Base Class ===" << endl;

    TeachingAssistant ta("Dr. Clara Oswald", 27, 4012, 9081, 45000.0, "Object Oriented Programming Lab");
    ta.displayProfile();

    return 0;
}
