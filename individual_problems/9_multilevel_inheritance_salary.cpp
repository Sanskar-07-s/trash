// Problem Statement:
// Problem 9: Demonstrate multilevel inheritance:
// a) Base class: Person -> data: name, age
// b) Derived class 1: Employee -> data: empId, designation
// c) Derived class 2: Salary -> data: basic, hra, da
//    Member function: calculateNetSalary()
// Create an object of Salary and display complete details of the employee with the net salary.

#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << " years" << endl;
    }
};

// Derived class 1
class Employee : public Person {
protected:
    int empId;
    string designation;

public:
    Employee(string n, int a, int id, string desig)
        : Person(n, a), empId(id), designation(desig) {}

    void displayEmployee() const {
        displayPerson();
        cout << "Employee ID : " << empId << endl;
        cout << "Designation : " << designation << endl;
    }
};

// Derived class 2
class Salary : public Employee {
private:
    double basic;
    double hra;
    double da;

public:
    Salary(string n, int a, int id, string desig, double b, double h, double d)
        : Employee(n, a, id, desig), basic(b), hra(h), da(d) {}

    double calculateNetSalary() const {
        return basic + hra + da;
    }

    void displaySalarySlip() const {
        cout << "\n==============================================" << endl;
        cout << "           EMPLOYEE SALARY DETAILS            " << endl;
        cout << "==============================================" << endl;
        displayEmployee();
        cout << "----------------------------------------------" << endl;
        cout << "Basic Salary : Rs. " << basic << endl;
        cout << "HRA          : Rs. " << hra << endl;
        cout << "DA           : Rs. " << da << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Net Salary   : Rs. " << calculateNetSalary() << endl;
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Multilevel Inheritance: Person -> Employee -> Salary ===" << endl;

    Salary emp("Marcus Brody", 42, 8092, "Technical Project Lead", 82000.0, 16400.0, 9840.0);
    emp.displaySalarySlip();

    return 0;
}
