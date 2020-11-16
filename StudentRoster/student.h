#pragma once
using namespace std;
#include <string>
#include "degree.h"
class Student	{
	private:
		static const short MAX_CLASSES = 100;
		string studentID;
		string firstName;
		string lastName;
		string email;
		unsigned short age;
		int numberDaysPerClass[MAX_CLASSES];
		DegreeProgram degreeProgram;
	
		
	

		
public:
    //constructor
    Student() {

    }
    ~Student() {

    }
    string getStudentID() const { return studentID; }
    void setStudentID(string studentID) { this->studentID = studentID; }

    string getFirstName() const { return firstName; }
    void setFirstName(string firstName) { this->firstName = firstName; }

    string getLastName() const { return lastName; }
    void setLastName(string lastName) { this->lastName = lastName; }

    string getEmail() const { return email; }
    void setEmail(string email) { this->email = email; }

    unsigned short getAge() const { return age; }
    void setAge(unsigned short age) { this->age = age; }

    //refactor using pointers as is it is not right
    int getNumberDaysPerClass() const { return numberDaysPerClass[MAX_CLASSES]; }
    void setNumberDaysPerClass(int numberDaysPerClass[]) { this->numberDaysPerClass = numberDaysPerClass; }

    DegreeProgram getDegreeProgram() const { return degreeProgram; }
    void setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

};

