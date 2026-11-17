#include <iostream>
#include <string>

using namespace std;

// ====================================================================
// Part A: Multiple Inheritance - Professor derived from Teacher & Researcher
// ====================================================================

// Base Class 1: Teacher
class Teacher {
protected:
    string subjectTaught;
    int teachingExperienceYears;

public:
    Teacher(string sub = "", int exp = 0)
        : subjectTaught(sub), teachingExperienceYears(exp) {}

    void displayTeacherDetails() const {
        cout << "Subject Taught      : " << subjectTaught << endl;
        cout << "Teaching Experience : " << teachingExperienceYears << " years" << endl;
    }
};

// Base Class 2: Researcher
class Researcher {
protected:
    string researchDomain;
    int publicationsCount;

public:
    Researcher(string domain = "", int pubs = 0)
        : researchDomain(domain), publicationsCount(pubs) {}

    void displayResearcherDetails() const {
        cout << "Research Domain     : " << researchDomain << endl;
        cout << "Publications Count  : " << publicationsCount << " papers" << endl;
    }
};

// Derived Class: Professor (Multiple Inheritance)
class Professor : public Teacher, public Researcher {
private:
    string professorName;
    string university;

public:
    Professor(string name, string uni, string sub, int exp, string domain, int pubs)
        : Teacher(sub, exp), Researcher(domain, pubs), professorName(name), university(uni) {}

    void displayProfile() const {
        cout << "\n========================================" << endl;
        cout << "          PROFESSOR FULL PROFILE        " << endl;
        cout << "========================================" << endl;
        cout << "Professor Name      : " << professorName << endl;
        cout << "University          : " << university << endl;
        cout << "----------------------------------------" << endl;
        displayTeacherDetails();
        displayResearcherDetails();
        cout << "========================================" << endl;
    }
};

// ====================================================================
// Part B: Operator Overloading - Overload '+' for Complex Numbers
// ====================================================================

class ComplexVal {
private:
    float real;
    float imag;

public:
    ComplexVal(float r = 0.0f, float i = 0.0f) : real(r), imag(i) {}

    // Overloading '+' operator
    ComplexVal operator+(const ComplexVal& other) const {
        return ComplexVal(real + other.real, imag + other.imag);
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 24: MULTIPLE INHERITANCE & OPERATOR OVERLOAD    " << endl;
    cout << "============================================================" << endl;

    // --- Part A: Multiple Inheritance Demo ---
    cout << "\n--- Part A: Multiple Inheritance (Teacher + Researcher -> Professor) ---" << endl;
    Professor prof(
        "Dr. Eleanor Vance", 
        "National Institute of Technology", 
        "Advanced Quantum Computing", 
        15, 
        "Quantum Algorithms & Cryptography", 
        28
    );
    prof.displayProfile();

    // --- Part B: Operator Overloading '+' for Complex Numbers ---
    cout << "\n--- Part B: Operator Overloading '+' for Complex Numbers ---" << endl;
    ComplexVal c1(4.2f, 5.8f);
    ComplexVal c2(3.1f, -2.4f);

    cout << "Complex Number 1: "; c1.display();
    cout << "Complex Number 2: "; c2.display();

    ComplexVal result = c1 + c2;
    cout << "\nResult of (c1 + c2) using overloaded '+': ";
    result.display();

    return 0;
}
