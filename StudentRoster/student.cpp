
#include "student.h"
int Student::getNumberDaysPerClass(int numberClass) const {
    if (numberClass >= 0 && numberClass < MAX_CLASSES) {
        return numberDaysPerClass[numberClass];
    }
    else {
        std::cout << "MG: array index in getter is out of boundaries.\n";
        return NULL;
    }
}
void  Student::setNumberDaysPerClass(int numberDaysPerClass, int numberClass) {
    if (numberClass >= 0 && numberClass < MAX_CLASSES) {
        this->numberDaysPerClass[numberClass] = numberDaysPerClass;
    }
    else {
        std::cout << "MG: array index in setter is out of boundaries.\n";
        for (int i = 0; i++; MAX_CLASSES) {
            this->numberDaysPerClass[i] = NULL;
        }
    }
}
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
void Student::print() {
    std::cout << "\n";
    std::cout << getStudentID() << ", ";
    std::cout << getFirstName() << ", ";
    std::cout << getLastName() << ", ";
    std::cout << getEmail() << ", ";
    std::cout << getAge() << ", ";
    std::cout << getNumberDaysPerClass(0) << ", ";
    std::cout << getNumberDaysPerClass(1) << ", ";
    std::cout << getNumberDaysPerClass(2) << ", ";
    std::cout << getDegreeProgram();
}
