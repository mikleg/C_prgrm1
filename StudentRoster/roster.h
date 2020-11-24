#pragma once
#include "student.h"
class Roster{
private:
	static const short MAX_STUDENTS = 10000;
	int currentNumStudents;
	Student* classRosterArray[MAX_STUDENTS];
public:
	//constructor
	Roster() {

	}
	~Roster() {

	}
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		 int numberDaysPerClass[], int sizeDaysPerClass, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

