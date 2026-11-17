// Problem Statement:
// Problem 3: Encapsulation - Class BankAccount with deposit, withdraw, and display functions.

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    // Encapsulated data members: inaccessible directly from outside the class
    long accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(long accNo, string holderName, double initialBalance) {
        accountNumber = accNo;
        accountHolder = holderName;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: Rs. " << amount << ". Current Balance: Rs. " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds! Current Balance is only Rs. " << balance << endl;
        } else {
            balance -= amount;
            cout << "Successfully withdrew: Rs. " << amount << ". Remaining Balance: Rs. " << balance << endl;
        }
    }

    void display() const {
        cout << "\n--- Account Statement ---" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }
};

int main() {
    cout << "=== Encapsulation: BankAccount ===" << endl;

    BankAccount myAccount(9876543210L, "John Smith", 10000.0);
    myAccount.display();

    cout << "\nPerforming Transactions:" << endl;
    myAccount.deposit(4500.0);
    myAccount.withdraw(2000.0);
    myAccount.withdraw(25000.0); // Should reject due to insufficient funds

    myAccount.display();

    return 0;
}
