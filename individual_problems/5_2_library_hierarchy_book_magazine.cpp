// Problem Statement:
// Problem 2: Implement a class hierarchy for a simple library system with a base class LibraryItem 
// and derived classes Book and Magazine. (Class must have attributes, methods and constructors)

#include <iostream>
#include <string>

using namespace std;

// Base class
class LibraryItem {
protected:
    int itemId;
    string title;

public:
    LibraryItem(int id = 0, string t = "Untitled") : itemId(id), title(t) {}

    virtual void displayDetails() const {
        cout << "Item ID : " << itemId << " | Title : " << title;
    }

    virtual ~LibraryItem() {}
};

// Derived class: Book
class Book : public LibraryItem {
private:
    string author;
    int pageCount;

public:
    Book(int id, string t, string a, int pages)
        : LibraryItem(id, t), author(a), pageCount(pages) {}

    void displayDetails() const override {
        cout << "[BOOK] ";
        LibraryItem::displayDetails();
        cout << " | Author: " << author << " | Pages: " << pageCount << endl;
    }
};

// Derived class: Magazine
class Magazine : public LibraryItem {
private:
    int issueNumber;
    string monthOfPublication;

public:
    Magazine(int id, string t, int issue, string month)
        : LibraryItem(id, t), issueNumber(issue), monthOfPublication(month) {}

    void displayDetails() const override {
        cout << "[MAGAZINE] ";
        LibraryItem::displayDetails();
        cout << " | Issue No: #" << issueNumber << " | Month: " << monthOfPublication << endl;
    }
};

int main() {
    cout << "=== Library Hierarchy: LibraryItem -> Book & Magazine ===" << endl;

    Book b1(101, "The C++ Programming Language", "Bjarne Stroustrup", 1368);
    Magazine m1(201, "IEEE Software Engineering Review", 42, "November 2026");

    cout << "\nDisplaying Library Records:" << endl;
    b1.displayDetails();
    m1.displayDetails();

    return 0;
}
