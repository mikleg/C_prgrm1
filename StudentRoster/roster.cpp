#include "roster.h"
Roster::Roster() {
	this->currentNumStudents = 0;
	for (int i = 0; i < MAX_STUDENTS; i++) { //initialization 
		this->classRosterArray[currentNumStudents] = NULL;
	}
}

DegreeProgram Roster::degreeParser(const string str) {
	if (str == "SECURITY") {
		return SECURITY;
	}
	else if (str == "NETWORK") {
		return NETWORK;
		return NETWORK;
	}
	else if (str == "SOFTWARE") {
		return SOFTWARE;
	}
	else return SECURITY;

}

Roster::Roster(const string dataArray[], size_t size) {
	this->currentNumStudents = 0;
	for (int i = 0; i < MAX_STUDENTS; i++) { //initialization check that without it
		this->classRosterArray[currentNumStudents] = NULL;
	}
	for (int i = 0; i < size; i++) {
		short fieldNumber = 0;
		short previousPosition = 0;
		string id, firstName, lastName, emailAddress;
		short unsigned age =0;
		int localDaysInCourse[3] = { 0,0,0 };
		DegreeProgram degreeprogram = NETWORK;
		for (int j = 0; j < (dataArray[i].length()); j++) {
			if (dataArray[i][j] == ',') {
				fieldNumber++;
				if (fieldNumber == 1) {
					id = dataArray[i].substr(0, j);
					previousPosition = j;
				}
				else if (fieldNumber == 2) {
					firstName = dataArray[i].substr(previousPosition + 1, j - previousPosition-1);
					previousPosition = j;
				}
				else if (fieldNumber == 3) {
					lastName = dataArray[i].substr(previousPosition + 1, j - previousPosition-1);
					previousPosition = j;
				}
				else if (fieldNumber == 4) {
					emailAddress = dataArray[i].substr(previousPosition + 1, j - previousPosition-1);
					previousPosition = j;
				}
				else if (fieldNumber == 5) {
					age = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					previousPosition = j;
				}
				else if (fieldNumber == 6) {
					localDaysInCourse[0] = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					previousPosition = j;
				}
				else if (fieldNumber == 7) {
					localDaysInCourse[1] = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					previousPosition = j;
				}
				else if (fieldNumber == 8) {
					localDaysInCourse[2] = stoi(dataArray[i].substr(previousPosition + 1, j - previousPosition));
					degreeprogram = degreeParser(dataArray[i].substr(j+1, dataArray[i].length() - previousPosition));
				}
			}
		}
		add(id, firstName, lastName, emailAddress, age, localDaysInCourse, degreeprogram);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse[3], DegreeProgram degreeprogram) {
	this->classRosterArray[currentNumStudents] = new Student(studentID, firstName, lastName, emailAddress, age, &daysInCourse, degreeprogram);
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
	cout << "attempt to delete studentID: " << studentID << "\n";
	bool noResult = true;
	for (int i = 0; i < currentNumStudents; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
				//delete actual object. 
			delete classRosterArray[i];
			//shift all elements of array
			for (int j = i; j < currentNumStudents-1; j++) {
				classRosterArray[j] = classRosterArray[j+1];
			}
			currentNumStudents--; //exlude the last element
			noResult = false;
			cout << "ID " << studentID << " was deleted\n";
			break; //exit from loop
		}
	}
	if (noResult) cout << "ID "<< studentID << " was not found\n";
}

void Roster::printAll() {
	cout << "Printing all students:\n";
	for (int i = 0; i < currentNumStudents; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(const string studentID) {
		for (int i = 0; i < currentNumStudents; i++) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				std::cout << classRosterArray[i]->getStudentID() << "\t";
				std::cout << classRosterArray[i]->getFirstName() << "\t";
				std::cout << classRosterArray[i]->getLastName() << "\t";
				cout << "Average days in course:\t" << (classRosterArray[i]->getDaysInCourse()[0]
					+ classRosterArray[i]->getDaysInCourse()[1]
					+ classRosterArray[i]->getDaysInCourse()[2]) / 3 << "\n";
			break; //exit from loop
		}
	}
}

void Roster::printByDegreeProgram(const DegreeProgram degreeProgram) {
	cout << "Printing ByDegreeProgram:\n";
	for (int i = 0; i < currentNumStudents; i++) {
		if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "Printing InvalidEmails:\n";
	for (int i = 0; i < currentNumStudents; i++) {
		if (!classRosterArray[i]->getEmailIsValid()) {
			classRosterArray[i]->printEmail();
		}
	}
}
