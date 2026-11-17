#include <iostream>
#include <string>

using namespace std;

// ====================================================================
// Part 1: Multiple Inheritance - Educational Institute Database
// Base 1: AcademicDetails, Base 2: SportsDetails -> Derived: StudentProfile
// ====================================================================

class AcademicDetails {
protected:
    string course;
    float gpa;

public:
    AcademicDetails(string c = "B.Tech", float g = 0.0f) : course(c), gpa(g) {}

    void displayAcademic() const {
        cout << "Course : " << course << " | GPA: " << gpa << endl;
    }
};

class SportsDetails {
protected:
    string sportName;
    string sportsGrade;

public:
    SportsDetails(string s = "None", string gr = "N/A") : sportName(s), sportsGrade(gr) {}

    void displaySports() const {
        cout << "Sport  : " << sportName << " | Sports Grade: " << sportsGrade << endl;
    }
};

class StudentProfile : public AcademicDetails, public SportsDetails {
private:
    int studentId;
    string studentName;

public:
    StudentProfile(int id, string name, string c, float g, string s, string gr)
        : AcademicDetails(c, g), SportsDetails(s, gr), studentId(id), studentName(name) {}

    void displayProfile() const {
        cout << "\n--- Student Comprehensive Profile (Multiple Inheritance) ---" << endl;
        cout << "ID     : " << studentId << " | Name: " << studentName << endl;
        displayAcademic();
        displaySports();
    }
};

// ====================================================================
// Part 2: Hybrid Inheritance (Diamond Hierarchy with Virtual Base Class)
//
//            Person (Virtual Base)
//           /      \
//       Student    Employee
//           \      /
//        TeachingAssistant
// ====================================================================

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class StudentMember : virtual public Person {
protected:
    int rollNo;

public:
    StudentMember(string n, int a, int r) : Person(n, a), rollNo(r) {}
};

class EmployeeMember : virtual public Person {
protected:
    int empId;
    double stipend;

public:
    EmployeeMember(string n, int a, int id, double s) : Person(n, a), empId(id), stipend(s) {}
};

class TeachingAssistant : public StudentMember, public EmployeeMember {
private:
    string assignedCourse;

public:
    // With virtual base class, the most derived class directly initializes the virtual base Person
    TeachingAssistant(string n, int a, int r, int id, double s, string course)
        : Person(n, a), StudentMember(n, a, r), EmployeeMember(n, a, id, s), assignedCourse(course) {}

    void displayTADetails() const {
        cout << "\n--- Teaching Assistant Details (Hybrid Inheritance) ---" << endl;
        displayPerson(); // Single unambiguous copy of Person
        cout << "Roll No       : " << rollNo << endl;
        cout << "Employee ID   : " << empId << endl;
        cout << "Monthly Pay   : Rs. " << stipend << endl;
        cout << "TA Course     : " << assignedCourse << endl;
    }
};

int main() {
    cout << "============================================================" << endl;
    cout << " EXPERIMENT 7: MULTIPLE AND HYBRID INHERITANCE              " << endl;
    cout << "============================================================" << endl;

    // Part 1: Multiple Inheritance
    StudentProfile sp(101, "Ethan Hunt", "Computer Science", 9.4f, "Badminton", "A+");
    sp.displayProfile();

    // Part 2: Hybrid Inheritance
    TeachingAssistant ta("Dr. Sarah Connor", 26, 8042, 9011, 35000.0, "Data Structures");
    ta.displayTADetails();

    return 0;
}
