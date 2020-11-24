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
		
public:
    //basic destructor

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
    int getNumberDaysPerClass(int numberClass) const {}
    void setNumberDaysPerClass(int numberDaysPerClass[], int numberClass) {}
        /*int getNumberDaysPerClass(int numberClass) const {
        if (numberClass >= 0 && numberClass < MAX_CLASSES) {
            return numberDaysPerClass[numberClass];
        }
        else {
            std::cout << "MG: array index in getter is out of boundaries.\n";
            return NULL;
        }
    }*/
   /* void setNumberDaysPerClass(int numberDaysPerClass, int numberClass) {
        if (numberClass >= 0 && numberClass < MAX_CLASSES) {
            this->numberDaysPerClass[numberClass] = numberDaysPerClass;
        }
        else {
            std::cout << "MG: array index in setter is out of boundaries.\n";
            for (int i = 0; i++; MAX_CLASSES) {
                this->numberDaysPerClass[i] = NULL;
            }
        }
    }*/

    DegreeProgram getDegreeProgram() const { return degreeProgram; }
    void setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }
    Student(string studentID, string firstName, string lastName, string email, unsigned short age,
            int numberDaysPerClass[], int sizeDaysPerClass,
            DegreeProgram degreeProgram) {}
    void print();

};

