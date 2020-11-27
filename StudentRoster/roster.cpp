#include "roster.h"
Roster::Roster() {
	this->currentNumStudents = 0;
	for (int i = 0; i < MAX_STUDENTS; i++) { //initialization check that without it
		this->classRosterArray[currentNumStudents] = NULL;
	}
}

DegreeProgram Roster::degreeParser(const string str) {
	if (str == "SECURITY") {
		return SECURITY;
	}
	else if (str == "NETWORK") {
		return NETWORK;
	}
	else if (str == "SOFTWARE") {
		return SOFTWARE;
	}
	else return SECURITY;

}

Roster::Roster(const string dataArray[]) {
	this->currentNumStudents = 0;
	for (int i = 0; i < MAX_STUDENTS; i++) { //initialization check that without it
		this->classRosterArray[currentNumStudents] = NULL;
	}
	for (int i = 0; i < sizeof(dataArray); i++) {
		short fieldNumber = 0;
		short previousPosition = 0;
		string id, firstName, lastName, emailAddress;
		short unsigned age =0;
		int daysInCourse[] = { 0,0,0 };
		DegreeProgram degreeprogram = NETWORK;
		for (int j = 0; j < (dataArray[i].length()); j++) {
			if (dataArray[i][j] == ',') {
				fieldNumber++;
				if (fieldNumber == 1) {
					id = dataArray[i].substr(0, j);
					previousPosition = j;
				}
				else if (fieldNumber == 2) {
					firstName = dataArray[i].substr(previousPosition + 1, j - previousPosition);
					previousPosition = j;
				}
				else if (fieldNumber == 3) {
					lastName = dataArray[i].substr(previousPosition + 1, j - previousPosition);
					previousPosition = j;
				}
				else if (fieldNumber == 4) {
					emailAddress = dataArray[i].substr(previousPosition + 1, j - previousPosition);
					previousPosition = j;
				}
				else if (fieldNumber == 5) {
					age = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					previousPosition = j;
				}
				else if (fieldNumber == 6) {
					daysInCourse[0] = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					previousPosition = j;
				}
				else if (fieldNumber == 7) {
					daysInCourse[1] = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					previousPosition = j;
				}
				else if (fieldNumber == 8) {
					daysInCourse[2] = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					degreeprogram = degreeParser(dataArray[i].substr(j+1, dataArray[i].length() - previousPosition));
				}
			}
		}
		add(id, firstName, lastName, emailAddress, age, daysInCourse, 3, degreeprogram);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse[], int numberCourses, DegreeProgram degreeprogram) {
	this->classRosterArray[currentNumStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, numberCourses, degreeprogram);
	currentNumStudents ++;
}
Student Roster::getStudentByNumber(const int number) {
	if (number <= currentNumStudents) {
		return *classRosterArray[number];
	}
	else {
		return Student("NULL"); //not valid record
	}

}

void Roster::remove(const string studentID) {
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
	cout << "ID was not found\n";
}

void Roster::printAll() {
	for (int i = 0; i < currentNumStudents; i++) {
		Student tempInstanceStudent = *classRosterArray[i];
		tempInstanceStudent.print();
	}
}

void Roster::printAverageDaysInCourse(const string studentID) {
	for (int i = 0; i < currentNumStudents; i++) {
		// get shallow copy of actual object
		Student tempInstanceStudent = *classRosterArray[i];
		if (studentID == tempInstanceStudent.getStudentID()) {
			cout << (tempInstanceStudent.getDaysInCourse()[0]
				+ tempInstanceStudent.getDaysInCourse()[1]
				+ tempInstanceStudent.getDaysInCourse()[2]) / 3;
		}
		break; //exit from loop
	}
	cout << "ID" << studentID << "was not found\n";
}

void Roster::printByDegreeProgram(const DegreeProgram degreeProgram) {
	for (int i = 0; i < currentNumStudents; i++) {
		// get shallow copy of actual object
		Student tempInstanceStudent = *classRosterArray[i];
		if (degreeProgram == tempInstanceStudent.getDegreeProgram()) {
			tempInstanceStudent.print();
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < currentNumStudents; i++) {
		Student tempInstanceStudent = *classRosterArray[i];
		if (!tempInstanceStudent.getEmailIsValid()) {
			tempInstanceStudent.print();
		}
	}
}
