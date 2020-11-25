#include "roster.h"
Roster::Roster() {
	this->currentNumStudents = 0;
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse[], int numberCorses, DegreeProgram degreeprogram) {
	//Student instanceStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, numberCorses, degreeprogram);
	//this->classRosterArray[currentNumStudents] = &instanceStudent;
		//Student instanceStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, numberCorses, degreeprogram);
	this->classRosterArray[currentNumStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, numberCorses, degreeprogram);
	currentNumStudents ++;
}
void Roster::remove(string studentID) {
	for (int i = 0; i < currentNumStudents; i++) {
		// get shallow copy of actual object
		Student tempInstanceStudent = *classRosterArray[i];
		if (studentID == tempInstanceStudent.getStudentID()) {
				//delete actual object. 
			delete classRosterArray[i];
			//shift all elements of array
			for (int j = i; j < currentNumStudents-1; j++) {
				classRosterArray[j] = classRosterArray[j+1];
			}
			currentNumStudents--; //exlude the last element
		}
		break; //exit from loop
	}
}
void Roster::printAll() {
	for (int i = 0; i < currentNumStudents; i++) {
		Student tempInstanceStudent = *classRosterArray[i];
		tempInstanceStudent.print();
	}
}
