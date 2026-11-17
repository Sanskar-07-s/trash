#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StudentFileRecord {
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
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 11: FILE I/O - WRITE & READ STUDENT DATA        " << endl;
    cout << "============================================================" << endl;

    const string filename = "simple.txt";

    // 1. Writing data to file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    int n;
    cout << "Enter number of students to write to file: ";
    if (!(cin >> n) || n <= 0) n = 2;

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter student " << (i + 1) << " data:" << endl;
        StudentFileRecord s;
        s.input();
        // Storing as: rollNo, name, marks
        outFile << s.rollNo << "\n" << s.name << "\n" << s.marks << "\n";
    }
    outFile.close();
    cout << "\n[Success] Student data successfully written to \"" << filename << "\"." << endl;

    // 2. Reading data from file
    cout << "\n--- Reading Data Back from \"" << filename << "\" ---" << endl;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    int roll;
    string studentName;
    float m;
    int count = 1;

    while (inFile >> roll) {
        inFile.ignore(); // Consume the newline after roll
        getline(inFile, studentName);
        inFile >> m;

        cout << "Record " << count++ << ": Roll: " << roll 
             << " | Name: " << studentName 
             << " | Marks: " << m << endl;
    }

    inFile.close();
    return 0;
}
