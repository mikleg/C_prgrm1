// StudentRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
//using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    
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

