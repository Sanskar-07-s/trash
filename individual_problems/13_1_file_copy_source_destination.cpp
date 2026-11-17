// Problem Statement:
// Problem 1: Write a program to copy the contents of one text file into another.
// a) Read data from source.txt
// b) Write the same data into destination.txt

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "=== File Copy Program: source.txt -> destination.txt ===" << endl;

    const string sourceFile = "source.txt";
    const string destFile = "destination.txt";

    // 1. Create and populate source.txt with sample text
    {
        ofstream initSource(sourceFile);
        initSource << "Line 1: Computer Science & Engineering.\n";
        initSource << "Line 2: Object-Oriented Programming with C++.\n";
        initSource << "Line 3: File Handling and Streams Demonstration.\n";
        initSource.close();
    }
    cout << "Sample data written to \"" << sourceFile << "\"." << endl;

    // 2. Open source.txt for reading
    ifstream src(sourceFile, ios::in);
    if (!src) {
        cerr << "Error: Could not open source file: " << sourceFile << endl;
        return 1;
    }

    // 3. Open destination.txt for writing
    ofstream dest(destFile, ios::out);
    if (!dest) {
        cerr << "Error: Could not open destination file: " << destFile << endl;
        src.close();
        return 1;
    }

    // 4. Character-by-character copy
    char ch;
    int count = 0;
    while (src.get(ch)) {
        dest.put(ch);
        count++;
    }

    src.close();
    dest.close();

    cout << "[Success] Copied " << count << " characters from \"" 
         << sourceFile << "\" into \"" << destFile << "\"." << endl;

    // 5. Verification - Display contents of destination.txt
    cout << "\n--- Contents of \"" << destFile << "\" ---" << endl;
    ifstream verify(destFile);
    string line;
    while (getline(verify, line)) {
        cout << "  " << line << endl;
    }
    verify.close();

    return 0;
}
