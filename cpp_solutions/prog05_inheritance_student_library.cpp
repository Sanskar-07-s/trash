#include <iostream>
#include <string>

using namespace std;

// ====================================================================
// Problem 1: Multilevel Inheritance (Student -> Test -> Result)
// ====================================================================

class Student {
protected:
    int rollNo;
    string name;

public:
    Student(int r = 0, string n = "") : rollNo(r), name(n) {}

    void displayStudent() const {
        cout << "Roll No: " << rollNo << "\nName   : " << name << endl;
    }
};

class Test : public Student {
protected:
    float mark1;
    float mark2;

public:
    Test(int r, string n, float m1, float m2) : Student(r, n), mark1(m1), mark2(m2) {}

    void displayMarks() const {
        cout << "Mark 1 : " << mark1 << "\nMark 2 : " << mark2 << endl;
    }
};

class Result : public Test {
private:
    float total;

public:
    Result(int r, string n, float m1, float m2) : Test(r, n, m1, m2) {
        total = mark1 + mark2;
    }

    void displayResult() const {
        cout << "\n--- Student Exam Result ---" << endl;
        displayStudent();
        displayMarks();
        cout << "Total  : " << total << endl;
    }
};

// ====================================================================
// Problem 2: Library System Hierarchy (LibraryItem -> Book & Magazine)
// ====================================================================

class LibraryItem {
protected:
    int itemId;
    string title;

public:
    LibraryItem(int id = 0, string t = "") : itemId(id), title(t) {}

    virtual void displayInfo() const {
        cout << "Item ID: " << itemId << " | Title: " << title;
    }

    virtual ~LibraryItem() {}
};

class BookItem : public LibraryItem {
private:
    string author;
    int pageCount;

public:
    BookItem(int id, string t, string a, int pages)
        : LibraryItem(id, t), author(a), pageCount(pages) {}

    void displayInfo() const override {
        cout << "[Book] ";
        LibraryItem::displayInfo();
        cout << " | Author: " << author << " | Pages: " << pageCount << endl;
    }
};

class MagazineItem : public LibraryItem {
private:
    int issueNumber;
    string month;

public:
    MagazineItem(int id, string t, int issue, string m)
        : LibraryItem(id, t), issueNumber(issue), month(m) {}

    void displayInfo() const override {
        cout << "[Magazine] ";
        LibraryItem::displayInfo();
        cout << " | Issue: #" << issueNumber << " | Month: " << month << endl;
    }
};

int main() {
    cout << "==========================================================" << endl;
    cout << " EXPERIMENT 5: INHERITANCE (STUDENT RESULT & LIBRARY SYSTEM)" << endl;
    cout << "==========================================================" << endl;

    // Demonstration of Problem 1
    cout << "\n--- Problem 1: Student -> Test -> Result ---" << endl;
    Result res(101, "Alice Smith", 88.5f, 92.0f);
    res.displayResult();

    // Demonstration of Problem 2
    cout << "\n--- Problem 2: Library Hierarchy (Book and Magazine) ---" << endl;
    BookItem b(2001, "The C++ Programming Language", "Bjarne Stroustrup", 1368);
    MagazineItem m(3001, "IEEE Software", 5, "September 2026");

    b.displayInfo();
    m.displayInfo();

    return 0;
}
