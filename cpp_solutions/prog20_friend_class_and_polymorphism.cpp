#include <iostream>

using namespace std;

// ====================================================================
// Part A: Friend Class - Calculator accessing Rectangle's private data
// ====================================================================

class Rectangle {
private:
    double length;
    double breadth;

public:
    Rectangle(double l = 0.0, double b = 0.0) : length(l), breadth(b) {}

    // Declaring Calculator as a friend class
    friend class RectangleCalculator;
};

class RectangleCalculator {
public:
    double computeArea(const Rectangle& rect) const {
        // Can access private members length and breadth directly
        return rect.length * rect.breadth;
    }

    double computePerimeter(const Rectangle& rect) const {
        return 2 * (rect.length + rect.breadth);
    }
};

// ====================================================================
// Part B: Runtime Polymorphism Demonstration
// ====================================================================

class BaseNotification {
public:
    virtual void sendAlert(const string& message) const {
        cout << "[Default Notification]: " << message << endl;
    }

    virtual ~BaseNotification() {}
};

class EmailNotification : public BaseNotification {
public:
    void sendAlert(const string& message) const override {
        cout << "[Email Alert Sent]: " << message << " (via SMTP Server)" << endl;
    }
};

class SMSNotification : public BaseNotification {
public:
    void sendAlert(const string& message) const override {
        cout << "[SMS Alert Sent]: " << message << " (via Telephony Gateway)" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 20: FRIEND CLASS & RUNTIME POLYMORPHISM         " << endl;
    cout << "============================================================" << endl;

    // --- Part A: Friend Class ---
    cout << "\n--- Part A: Friend Class Demonstration ---" << endl;
    Rectangle myRect(12.5, 4.0);
    RectangleCalculator calc;

    cout << "Rectangle dimensions: 12.5 x 4.0" << endl;
    cout << "Area calculated by Friend Class      : " << calc.computeArea(myRect) << endl;
    cout << "Perimeter calculated by Friend Class : " << calc.computePerimeter(myRect) << endl;

    // --- Part B: Runtime Polymorphism ---
    cout << "\n--- Part B: Runtime Polymorphism Demonstration ---" << endl;
    BaseNotification* notifier = nullptr;

    EmailNotification email;
    SMSNotification sms;

    notifier = &email;
    notifier->sendAlert("System backup completed successfully."); // Dynamically dispatched

    notifier = &sms;
    notifier->sendAlert("OTP for login is 492011."); // Dynamically dispatched

    return 0;
}
