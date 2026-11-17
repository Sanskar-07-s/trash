// Problem Statement:
// Problem 24 (a): Write a program to perform Multiple Inheritance - Class Professor derived from Teacher and Researcher.

#include <iostream>
#include <string>

using namespace std;

// Base Class 1: Teacher
class Teacher {
protected:
    string subjectTaught;
    int experienceYears;

public:
    Teacher(string subject = "", int exp = 0)
        : subjectTaught(subject), experienceYears(exp) {}

    void displayTeacherInfo() const {
        cout << "Subject Specialization : " << subjectTaught << endl;
        cout << "Teaching Experience    : " << experienceYears << " years" << endl;
    }
};

// Base Class 2: Researcher
class Researcher {
protected:
    string researchField;
    int researchPapersPublished;

public:
    Researcher(string field = "", int papers = 0)
        : researchField(field), researchPapersPublished(papers) {}

    void displayResearcherInfo() const {
        cout << "Research Field         : " << researchField << endl;
        cout << "Papers Published       : " << researchPapersPublished << " international publications" << endl;
    }
};

// Derived Class: Professor (Multiple Inheritance from Teacher and Researcher)
class Professor : public Teacher, public Researcher {
private:
    string professorName;
    string department;

public:
    Professor(string name, string dept, string subject, int exp, string field, int papers)
        : Teacher(subject, exp), Researcher(field, papers), professorName(name), department(dept) {}

    void displayProfessorProfile() const {
        cout << "\n==============================================" << endl;
        cout << "           PROFESSOR ACADEMIC PROFILE         " << endl;
        cout << "==============================================" << endl;
        cout << "Professor Name         : " << professorName << endl;
        cout << "Department             : " << department << endl;
        cout << "----------------------------------------------" << endl;
        displayTeacherInfo();
        displayResearcherInfo();
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Multiple Inheritance: Teacher + Researcher -> Professor ===" << endl;

    Professor prof(
        "Dr. Alistair Finch",
        "School of Computer Science",
        "Distributed Computing & Cloud Architecture",
        18,
        "Fault-Tolerant Distributed Consensus",
        34
    );

    prof.displayProfessorProfile();

    return 0;
}
