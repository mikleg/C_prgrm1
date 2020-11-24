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




		}
	}
}
