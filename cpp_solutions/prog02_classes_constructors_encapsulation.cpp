#include <iostream>
#include <string>

using namespace std;

// --- Problem 1: Class and Object ---
class Student {
public:
    int rollNo;
    string name;
    float mark;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Mark: ";
        cin >> mark;
    }

    void display() const {
        cout << "\nStudent Details:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name   : " << name << endl;
        cout << "Mark   : " << mark << endl;
    }
};

// --- Problem 2: Constructor and Destructor ---
class Book {
private:
    string title;
    string author;
    float price;

public:
    // Parameterized Constructor
    Book(string t, string a, float p) : title(t), author(a), price(p) {
        cout << "\n[Book Constructor Called] Book \"" << title << "\" created successfully." << endl;
    }

    void display() const {
        cout << "Title : " << title << " | Author: " << author << " | Price: Rs. " << price << endl;
    }

    // Destructor
    ~Book() {
        cout << "[Book Destructor Called] Book \"" << title << "\" is being destroyed." << endl;
    }
};

// --- Problem 3: Encapsulation ---
class BankAccount {
private:
    long accountNumber;
    string accountHolder;
    double balance; // Encapsulated private data

public:
    BankAccount(long accNo, string holder, double initialBal) {
        accountNumber = accNo;
        accountHolder = holder;
        balance = initialBal >= 0 ? initialBal : 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs. " << amount << ". New Balance: Rs. " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance! Available: Rs. " << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs. " << amount << ". Remaining Balance: Rs. " << balance << endl;
        }
    }

    void display() const {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Holder Name   : " << accountHolder << endl;
        cout << "Balance       : Rs. " << balance << endl;
    }
};

int main() {
    cout << "=================================================" << endl;
    cout << "  EXPERIMENT 2: CLASSES, CONSTRUCTORS & ENCAPS.  " << endl;
    cout << "=================================================" << endl;

    // Problem 1 Demonstration
    cout << "\n--- Problem 1: Class and Object ---" << endl;
    Student s1;
    s1.input();
    s1.display();

    // Problem 2 Demonstration
    cout << "\n--- Problem 2: Constructor and Destructor ---" << endl;
    {
        Book b1("Object Oriented Programming in C++", "Robert Lafore", 650.0f);
        b1.display();
        cout << "Leaving book scope..." << endl;
    } // b1 gets destroyed here, calling destructor

    // Problem 3 Demonstration
    cout << "\n--- Problem 3: Encapsulation (BankAccount) ---" << endl;
    BankAccount acc(1002345678, "Alex Mercer", 5000.0);
    acc.display();
    acc.deposit(2500.0);
    acc.withdraw(1200.0);
    acc.withdraw(8000.0); // should warn insufficient balance
    acc.display();

    return 0;
}
