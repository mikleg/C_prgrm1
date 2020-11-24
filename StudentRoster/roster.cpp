#include "roster.h"
Roster::Roster() {
	this->currentNumStudents = 0;
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse[], int numberCorses, DegreeProgram degreeprogram) {
	Student instanceStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, numberCorses, degreeprogram);



}
