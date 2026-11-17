#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ====================================================================
// Part A: Append Data to Existing File Without Overwriting
// ====================================================================

void appendToFileDemo(const string& filename) {
    // 1. Initial write (if not exists)
    {
        ofstream initialFile(filename, ios::out);
        initialFile << "Log entry 1: System initiated.\n";
        initialFile << "Log entry 2: Calibration finished.\n";
        initialFile.close();
    }

    cout << "Original file contents before append:" << endl;
    ifstream readBefore(filename);
    string line;
    while (getline(readBefore, line)) {
        cout << "  " << line << endl;
    }
    readBefore.close();

    // 2. Open file in append mode: ios::app
    ofstream appendStream(filename, ios::app);
    if (!appendStream) {
        cerr << "Failed to open file in append mode!" << endl;
        return;
    }

    appendStream << "Log entry 3: [APPENDED] New user logged in at 10:30 PM.\n";
    appendStream << "Log entry 4: [APPENDED] Process completed successfully.\n";
    appendStream.close();

    cout << "\nFile contents after appending (using ios::app):" << endl;
    ifstream readAfter(filename);
    while (getline(readAfter, line)) {
        cout << "  " << line << endl;
    }
    readAfter.close();
}

// ====================================================================
// Part B: Copy Constructor Demonstration
// ====================================================================

class Laptop {
private:
    string brand;
    string model;
    double price;

public:
    // Parameterized constructor
    Laptop(string b, string m, double p) : brand(b), model(m), price(p) {
        cout << "[Parameterized Constructor] Created Laptop " << brand << " " << model << endl;
    }

    // Explicit Copy Constructor: ClassName(const ClassName& source)
    Laptop(const Laptop& other) {
        brand = other.brand;
        model = other.model + " (Cloned Copy)";
        price = other.price;
        cout << "[Copy Constructor] Copied Laptop from " << other.brand << " " << other.model << endl;
    }

    void display() const {
        cout << "Laptop: " << brand << " " << model << " | Price: Rs. " << price << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 23: FILE APPEND & COPY CONSTRUCTOR              " << endl;
    cout << "============================================================" << endl;

    // --- Part A: File Append ---
    cout << "\n--- Part A: Appending Data to File Without Overwriting ---" << endl;
    appendToFileDemo("system_log.txt");

    // --- Part B: Copy Constructor ---
    cout << "\n--- Part B: Copy Constructor Demonstration ---" << endl;
    Laptop originalLaptop("Dell", "XPS 15", 145000.0);
    cout << "Original Object: ";
    originalLaptop.display();

    // Invoking copy constructor using initialization syntax
    cout << "\nCreating copy1 using: Laptop copy1 = originalLaptop;" << endl;
    Laptop copy1 = originalLaptop;
    cout << "Copy 1: ";
    copy1.display();

    // Invoking copy constructor using constructor call syntax
    cout << "\nCreating copy2 using: Laptop copy2(originalLaptop);" << endl;
    Laptop copy2(originalLaptop);
    cout << "Copy 2: ";
    copy2.display();

    return 0;
}
