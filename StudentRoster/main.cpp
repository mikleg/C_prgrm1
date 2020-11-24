// StudentRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <string>
//using namespace std;

int main()
{
    cout << "Hello World!\n";
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE" 
    }
    classRoster.printAll();

    classRoster.printInvalidEmails();



    //loop through classRosterArray and for each element:

    classRoster.printAverageDaysInCourse(/*current_object's student id*/);



    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");

    //expected: the above line should print a message saying such a student with this ID was not found.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

