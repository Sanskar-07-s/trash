// Problem Statement:
// Problem 20 (b): Write a program to demonstrate runtime polymorphism.

#include <iostream>

using namespace std;

// Base class
class Notification {
public:
    virtual void send(const string& message) const {
        cout << "[Default Notification] " << message << endl;
    }

    virtual ~Notification() {}
};

// Derived class 1: EmailNotification
class EmailNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "[Email Notification via SMTP]: " << message << endl;
    }
};

// Derived class 2: SMSNotification
class SMSNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "[SMS Notification via SMS Gateway]: " << message << endl;
    }
};

// Derived class 3: PushNotification
class PushNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "[Push Notification via Cloud Messaging]: " << message << endl;
    }
};

int main() {
    cout << "=== Runtime Polymorphism Demonstration ===" << endl;

    // Base pointer used to reference derived objects at runtime
    Notification* notifyPtr = nullptr;

    EmailNotification email;
    SMSNotification sms;
    PushNotification push;

    cout << "\n1. Dispatching via EmailNotification:" << endl;
    notifyPtr = &email;
    notifyPtr->send("Your verification code is 492019.");

    cout << "\n2. Dispatching via SMSNotification:" << endl;
    notifyPtr = &sms;
    notifyPtr->send("Your account was logged in from a new device.");

    cout << "\n3. Dispatching via PushNotification:" << endl;
    notifyPtr = &push;
    notifyPtr->send("New message received from instructor.");

    return 0;
}
