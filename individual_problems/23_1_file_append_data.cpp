// Problem Statement:
// Problem 23 (a): Write a program to Append Data - Append data to existing file without overwriting.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayFileContent(const string& filename) {
    ifstream reader(filename);
    if (!reader) {
        cout << "[File does not exist yet]" << endl;
        return;
    }
    string line;
    int lineNum = 1;
    while (getline(reader, line)) {
        cout << "  " << lineNum++ << ". " << line << endl;
    }
    reader.close();
}

int main() {
    cout << "=== File Handling: Append Data Without Overwriting ===" << endl;

    const string filename = "appended_log.txt";

    // 1. Initial write to establish baseline file
    {
        ofstream initFile(filename, ios::out);
        initFile << "[Log 09:00 AM] System boot sequence started.\n";
        initFile << "[Log 09:01 AM] All hardware diagnostics passed.\n";
        initFile.close();
    }

    cout << "\nFile contents before appending:" << endl;
    displayFileContent(filename);

    // 2. Open file with ios::app flag (Append mode)
    cout << "\nOpening file in APPEND mode (ios::app) and adding new entries..." << endl;
    ofstream appendStream(filename, ios::app);
    if (!appendStream) {
        cerr << "Error: Could not open file in append mode!" << endl;
        return 1;
    }

    appendStream << "[Log 10:15 AM] User admin successfully logged in.\n";
    appendStream << "[Log 11:30 AM] Scheduled database backup completed successfully.\n";
    appendStream.close();

    cout << "[Success] Data appended successfully without modifying earlier records." << endl;

    // 3. Verifying updated contents
    cout << "\nFile contents after appending:" << endl;
    displayFileContent(filename);

    return 0;
}
