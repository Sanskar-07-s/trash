// Problem Statement:
// Problem 10: Design an abstract class Account with a pure virtual function calculateInterest().
// Derive two classes:
// a) SavingsAccount -> calculate interest using simple interest
// b) CurrentAccount -> no interest
// Demonstrate runtime polymorphism by calling calculateInterest() using a base class pointer.

#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Account {
protected:
    long accountNumber;
    string holderName;
    double balance;

public:
    Account(long accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal) {}

    // Pure virtual function
    virtual double calculateInterest() const = 0;

    virtual void displayInfo() const {
        cout << "Account No : " << accountNumber << "\nHolder Name: " << holderName 
             << "\nBalance    : Rs. " << balance << endl;
    }

    virtual ~Account() {}
};

// Derived Class 1: SavingsAccount
class SavingsAccount : public Account {
private:
    float ratePercent;
    int timeYears;

public:
    SavingsAccount(long accNo, string name, double bal, float rate = 5.0f, int years = 1)
        : Account(accNo, name, bal), ratePercent(rate), timeYears(years) {}

    double calculateInterest() const override {
        // Simple Interest = (P * R * T) / 100
        return (balance * ratePercent * timeYears) / 100.0;
    }

    void displayInfo() const override {
        cout << "[Savings Account]" << endl;
        Account::displayInfo();
        cout << "Interest Rate: " << ratePercent << "% for " << timeYears << " year(s)" << endl;
    }
};

// Derived Class 2: CurrentAccount
class CurrentAccount : public Account {
public:
    CurrentAccount(long accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    // Current accounts earn no interest
    double calculateInterest() const override {
        return 0.0;
    }

    void displayInfo() const override {
        cout << "[Current Account]" << endl;
        Account::displayInfo();
        cout << "Interest Rate: 0.0% (No interest applicable)" << endl;
    }
};

int main() {
    cout << "=== Abstract Class Account & Runtime Polymorphism ===" << endl;

    SavingsAccount savAcc(123456789, "Arthur Dent", 60000.0, 6.0f, 2);
    CurrentAccount curAcc(987654321, "Megadodo Publications", 350000.0);

    // Base class pointer
    Account* accPtr = nullptr;

    cout << "\n1. Base pointer pointing to SavingsAccount object:" << endl;
    accPtr = &savAcc;
    accPtr->displayInfo();
    cout << "Dynamically resolved Interest: Rs. " << accPtr->calculateInterest() << endl;

    cout << "\n2. Base pointer pointing to CurrentAccount object:" << endl;
    accPtr = &curAcc;
    accPtr->displayInfo();
    cout << "Dynamically resolved Interest: Rs. " << accPtr->calculateInterest() << endl;

    return 0;
}
