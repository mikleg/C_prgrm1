
#include "student.h"
Student::Student(string studentID, string firstName, string lastName, string email, unsigned short age,
                int numberDaysPerClass1, int numberDaysPerClass2, int numberDaysPerClass3,
                DegreeProgram degreeProgram) {
    this->setStudentID(studentID);
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setEmail(email);
    this->setAge(age);
    this->setNumberDaysPerClass(numberDaysPerClass1, 0);
    this->setNumberDaysPerClass(numberDaysPerClass2, 1);
    this->setNumberDaysPerClass(numberDaysPerClass3, 2);
    this->setDegreeProgram(degreeProgram);
    
}
