// Problem Statement:
// Problem 1: Implement a program to perform multiple inheritance for the Educational Institute database.
// (Class must have attributes, methods and constructors)

#include <iostream>
#include <string>

using namespace std;

// Base Class 1: AcademicDetails
class AcademicDetails {
protected:
    string degreeCourse;
    float cgpa;

public:
    AcademicDetails(string course = "B.Tech", float gpa = 0.0f)
        : degreeCourse(course), cgpa(gpa) {}

    void displayAcademic() const {
        cout << "Course Enrolled : " << degreeCourse << endl;
        cout << "Current CGPA    : " << cgpa << " / 10.0" << endl;
    }
};

// Base Class 2: SportsDetails
class SportsDetails {
protected:
    string sportName;
    string achievementLevel;

public:
    SportsDetails(string sport = "None", string level = "N/A")
        : sportName(sport), achievementLevel(level) {}

    void displaySports() const {
        cout << "Sport Played    : " << sportName << endl;
        cout << "Achievement     : " << achievementLevel << endl;
    }
};

// Derived Class: StudentProfile (Multiple Inheritance)
class StudentProfile : public AcademicDetails, public SportsDetails {
private:
    int studentId;
    string studentName;

public:
    StudentProfile(int id, string name, string course, float gpa, string sport, string level)
        : AcademicDetails(course, gpa), SportsDetails(sport, level), studentId(id), studentName(name) {}

    void displayCompleteRecord() const {
        cout << "\n==============================================" << endl;
        cout << "   INSTITUTE STUDENT COMPREHENSIVE RECORD     " << endl;
        cout << "==============================================" << endl;
        cout << "Student ID      : " << studentId << endl;
        cout << "Student Name    : " << studentName << endl;
        cout << "----------------------------------------------" << endl;
        displayAcademic();
        displaySports();
        cout << "==============================================" << endl;
    }
};

int main() {
    cout << "=== Multiple Inheritance: Educational Institute Database ===" << endl;

    StudentProfile student(1024, "Alexander Wright", "Computer Engineering", 9.6f, "Basketball", "National Level Gold Medalist");
    student.displayCompleteRecord();

    return 0;
}
