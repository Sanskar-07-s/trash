// Problem Statement:
// Problem 11: Create a program to Write and read student data to/from a file simple.txt.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StudentFileHandler {
public:
    int rollNo;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll No: " << rollNo << " | Name: " << name << " | Marks: " << marks << endl;
    }
};

int main() {
    cout << "=== File Handling: Write and Read Student Data ===" << endl;

    const string filename = "simple.txt";

    // --- Part 1: Writing data to simple.txt ---
    cout << "\n--- Writing Records to \"" << filename << "\" ---" << endl;
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    int n;
    cout << "How many students do you want to store? ";
    if (!(cin >> n) || n <= 0) n = 2;

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter student " << (i + 1) << " info:" << endl;
        StudentFileHandler s;
        s.input();
        // Write roll, name, marks on separate lines
        outFile << s.rollNo << "\n" << s.name << "\n" << s.marks << "\n";
    }
    outFile.close();
    cout << "\n[Success] Data written to \"" << filename << "\" successfully." << endl;

    // --- Part 2: Reading data back from simple.txt ---
    cout << "\n--- Reading Records back from \"" << filename << "\" ---" << endl;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }

    int roll;
    string name;
    float marks;
    int recordIndex = 1;

    while (inFile >> roll) {
        inFile.ignore(); // Discard newline
        getline(inFile, name);
        inFile >> marks;

        cout << "Student #" << recordIndex++ << " -> Roll: " << roll 
             << " | Name: " << name 
             << " | Marks: " << marks << endl;
    }

    inFile.close();
    return 0;
}
