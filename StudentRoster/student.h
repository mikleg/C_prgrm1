#pragma once
using namespace std;
#include <string>
#include "degree.h"
#include <iostream>
class Student	{
    public:
        static const short MAX_CLASSES = 3;
    private:
        //static const short MAX_CLASSES = 100;
		string studentID;
		string firstName;
		string lastName;
		string email;
		unsigned short age;
		int numberDaysPerClass[MAX_CLASSES];
		DegreeProgram degreeProgram;
        bool emailIsValid;
		
public:
    //basic destructor

    ~Student() {

    }
    bool getEmailIsValid() const { return emailIsValid; }
    void setEmailIsValid(bool emailValid) { this->emailIsValid = emailValid; }
    
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
    int getNumberDaysPerClass(int numberClass) const;
    int *getDaysInCourse() {return numberDaysPerClass;}
    void setNumberDaysPerClass(int numberDaysPerClass[MAX_CLASSES]);
    DegreeProgram getDegreeProgram() const { return degreeProgram; }
    void setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }
    Student(string studentID, string firstName, string lastName, string email, unsigned short age,
        int *numberDaysPerClass[3], DegreeProgram degreeProgram);
    Student(string nullStudent);
    void print();
    void printEmail();
};

