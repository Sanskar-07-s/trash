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
        cout << "Age         : " << age << endl;
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
        cout << "\n========================================" << endl;
        cout << "           EMPLOYEE SALARY SLIP         " << endl;
        cout << "========================================" << endl;
        displayEmployee();
        cout << "Basic Pay   : Rs. " << basic << endl;
        cout << "HRA         : Rs. " << hra << endl;
        cout << "DA          : Rs. " << da << endl;
        cout << "----------------------------------------" << endl;
        cout << "Net Salary  : Rs. " << calculateNetSalary() << endl;
        cout << "========================================" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 9: MULTILEVEL INHERITANCE (PERSON-EMP-SALARY)   " << endl;
    cout << "============================================================" << endl;

    // Creating an object of Salary and displaying complete details
    Salary emp1("Johnathan Doe", 34, 10452, "Senior Software Engineer", 75000.0, 15000.0, 8500.0);
    emp1.displaySalarySlip();

    return 0;
}
