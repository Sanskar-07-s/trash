// Problem Statement:
// Problem 2: Constructor and Destructor - Class Book initialized using constructor, display message in destructor.

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    float price;

public:
    // Parameterized Constructor
    Book(string bTitle, string bAuthor, float bPrice) {
        title = bTitle;
        author = bAuthor;
        price = bPrice;
        cout << "[Constructor Called] Book \"" << title << "\" initialized successfully." << endl;
    }

    void displayInfo() const {
        cout << "Book: " << title << " | Author: " << author << " | Price: Rs. " << price << endl;
    }

    // Destructor
    ~Book() {
        cout << "[Destructor Called] Book \"" << title << "\" memory is being cleaned up and destroyed." << endl;
    }
};

int main() {
    cout << "=== Constructor and Destructor Demonstration ===" << endl;

    cout << "\nCreating Book object within inner block scope..." << endl;
    {
        Book myBook("Concepts of OOP in C++", "E. Balagurusamy", 550.0f);
        myBook.displayInfo();
        cout << "Exiting inner block scope now..." << endl;
    } // myBook is automatically destroyed here

    cout << "\nExecution continues after inner block scope." << endl;
    return 0;
}
