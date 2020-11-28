using namespace std;
#include <iostream>
#include <string>
#include "roster.h"

int main(){   
    cout << "The course title: Scripting and Programming - Applications - C867 " << "\n";
    cout << "The programming language: C++" << "\n";
    cout << "WGU student ID: #001211217" << "\n";
    cout << "Student name: Mikhail Gorbunov" << "\n\n";
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Mikhail,Gorbunov,mihailgorbunov74@gmail.com,43,30,30,30,SOFTWARE"
                                  
                                 };
    Roster *classRoster = new Roster(studentData, 5);
    classRoster->printAll();
    classRoster->printInvalidEmails();
    cout << "Printing AverageDaysInCourse:\n";
    for (int i = 0; i < classRoster->getCurrentNumStudents(); i++) {    
        if (classRoster->getStudentByNumber(i).getEmail() != "NULL") {
            classRoster->printAverageDaysInCourse(classRoster->getStudentByNumber(i).getStudentID());
        }
        else break;
    }
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    delete classRoster;
}