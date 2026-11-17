#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ====================================================================
// Part 1: File Copy Program (source.txt -> destination.txt)
// ====================================================================
void copyFile(const string& sourcePath, const string& destPath) {
    // Creating sample source file if not present
    {
        ofstream initSource(sourcePath);
        initSource << "This is line 1: Object-Oriented Programming with C++.\n";
        initSource << "This is line 2: Demonstrating file stream copy operations.\n";
        initSource << "This is line 3: End of file copy demo.\n";
    }

    ifstream src(sourcePath, ios::in);
    if (!src) {
        cerr << "Error: Could not open source file: " << sourcePath << endl;
        return;
    }

    ofstream dest(destPath, ios::out);
    if (!dest) {
        cerr << "Error: Could not open destination file: " << destPath << endl;
        src.close();
        return;
    }

    char ch;
    int charCount = 0;
    while (src.get(ch)) {
        dest.put(ch);
        charCount++;
    }

    src.close();
    dest.close();

    cout << "[Success] Copied " << charCount << " characters from \"" 
         << sourcePath << "\" to \"" << destPath << "\"." << endl;
}

// ====================================================================
// Part 2: Student Class - Automatic vs Manual Creation and Destruction
// ====================================================================
class StudentLifecycle {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Default constructor
    StudentLifecycle() : name("Default"), rollNumber(0), marks(0.0f) {
        cout << "  [Constructor] Default student object initialized." << endl;
    }

    // Parameterized constructor
    StudentLifecycle(string n, int r, float m) : name(n), rollNumber(r), marks(m) {
        cout << "  [Constructor] Student \"" << name << "\" (Roll: " << rollNumber << ") initialized." << endl;
    }

    // Destructor
    ~StudentLifecycle() {
        cout << "  [Destructor] Student \"" << name << "\" destroyed." << endl;
    }

    void input() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "  [Student Info] Roll: " << rollNumber << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 13: FILE COPY & OBJECT LIFECYCLE MANAGEMENT     " << endl;
    cout << "============================================================" << endl;

    // --- Part 1: File Copy ---
    cout << "\n--- Part 1: File Copy (source.txt -> destination.txt) ---" << endl;
    copyFile("source.txt", "destination.txt");

    // Verify destination contents
    cout << "\nContents of destination.txt:" << endl;
    ifstream destCheck("destination.txt");
    string line;
    while (getline(destCheck, line)) {
        cout << "  " << line << endl;
    }
    destCheck.close();

    // --- Part 2: Automatic vs Manual Object Creation ---
    cout << "\n--- Part 2: Automatic (Stack) vs Manual (Heap) Creation ---" << endl;

    cout << "\n1. Demonstrating Automatic (Stack-based) Object Creation:" << endl;
    {
        StudentLifecycle autoStudent("Sarah Connor", 101, 91.5f);
        autoStudent.display();
        cout << "Leaving local block scope..." << endl;
    } // autoStudent goes out of scope here; destructor called automatically

    cout << "\n2. Demonstrating Manual (Heap-based with new/delete) Object Creation:" << endl;
    // Dynamic allocation using 'new'
    StudentLifecycle* heapStudent = new StudentLifecycle("James Bond", 007, 98.0f);
    heapStudent->display();

    cout << "Explicitly deleting heap student using 'delete'..." << endl;
    delete heapStudent; // Manual deallocation triggers destructor
    heapStudent = nullptr;

    return 0;
}
