#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Account {
protected:
    long accountNumber;
    string customerName;
    double balance;

public:
    Account(long accNo, string name, double bal)
        : accountNumber(accNo), customerName(name), balance(bal) {}

    // Pure virtual function making Account an abstract class
    virtual double calculateInterest() const = 0;

    virtual void displayDetails() const {
        cout << "Account No : " << accountNumber << "\nCustomer   : " << customerName
             << "\nBalance    : Rs. " << balance << endl;
    }

    virtual ~Account() {} // Virtual destructor for proper polymorphic cleanup
};

// Derived Class: SavingsAccount
class SavingsAccount : public Account {
private:
    float rateOfInterest; // Annual interest rate in percent
    int timeInYears;

public:
    SavingsAccount(long accNo, string name, double bal, float rate = 4.0f, int time = 1)
        : Account(accNo, name, bal), rateOfInterest(rate), timeInYears(time) {}

    // Overriding pure virtual function
    double calculateInterest() const override {
        // Simple interest: (P * R * T) / 100
        return (balance * rateOfInterest * timeInYears) / 100.0;
    }

    void displayDetails() const override {
        cout << "[Savings Account]" << endl;
        Account::displayDetails();
        cout << "Interest Rate: " << rateOfInterest << "% for " << timeInYears << " year(s)" << endl;
        cout << "Calculated Interest: Rs. " << calculateInterest() << endl;
    }
};

// Derived Class: CurrentAccount
class CurrentAccount : public Account {
public:
    CurrentAccount(long accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    // Overriding pure virtual function (no interest for current account)
    double calculateInterest() const override {
        return 0.0;
    }

    void displayDetails() const override {
        cout << "[Current Account]" << endl;
        Account::displayDetails();
        cout << "Interest : No interest applicable (Rs. " << calculateInterest() << ")" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 10: ABSTRACT CLASS & RUNTIME POLYMORPHISM       " << endl;
    cout << "============================================================" << endl;

    // Polymorphism using Base Class Pointers
    Account* accPtr = nullptr;

    SavingsAccount savAcc(987654321, "Robert Frost", 50000.0, 5.5f, 2);
    CurrentAccount curAcc(123456789, "Stark Enterprises", 250000.0);

    cout << "\n--- Calling calculateInterest() via Base Pointer (Savings) ---" << endl;
    accPtr = &savAcc;
    accPtr->displayDetails();
    cout << "Direct call via base pointer -> calculateInterest(): Rs. " << accPtr->calculateInterest() << endl;

    cout << "\n--- Calling calculateInterest() via Base Pointer (Current) ---" << endl;
    accPtr = &curAcc;
    accPtr->displayDetails();
    cout << "Direct call via base pointer -> calculateInterest(): Rs. " << accPtr->calculateInterest() << endl;

    return 0;
}
