
#include "student.h"
#include<cstring>

int Student::getNumberDaysPerClass(int numberClass) const {
    if (numberClass >= 0 && numberClass < MAX_CLASSES) {
        return numberDaysPerClass[numberClass];
    }
    else {
        std::cout << "MG: array index in getter is out of boundaries.\n";
        return NULL;
    }
}
void  Student::setNumberDaysPerClass(int localNumberDaysPerClass[MAX_CLASSES]) {
    for (int i = 0; i < MAX_CLASSES;  i++) {
        this->numberDaysPerClass[i] = localNumberDaysPerClass[i];
    }

}

int symbPosition(string str, string symbol) {
    if (str.find(symbol) == str.rfind(symbol)
        && str.find(symbol) > 0
        && str.find(symbol) < str.length() - 1) { //if last find = first -> we have only one such symbol
        return str.find(symbol);
    }
    else return NULL;
}

bool domainIsValid(string domenPart) {
    if (domenPart.find(' ') == string::npos && domenPart.find('.') != string::npos)
        return true;
    else return false;
}

bool localIsValid(string localPart) {
    if (localPart.find(' ') == string::npos)
        return true;
    else return false;
}

bool mailIsValid(string email) {
    string localPart = "";
    string domenPart = "";
    if (symbPosition(email, "@") != NULL) {
        localPart = email.substr(0, symbPosition(email, "@"));
        domenPart = email.substr(symbPosition(email, "@") + 1, email.length() - symbPosition(email, "@") +1);
    }
    if (domainIsValid(domenPart) && localIsValid(localPart))
        return true;
    else return false;
}

Student::Student(string studentID, string firstName, string lastName, string email, unsigned short age,
                int *numberDaysPerClass[3], DegreeProgram degreeProgram) {
    this->setStudentID(studentID);
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setEmail(email);
    this->setAge(age);
    this->setNumberDaysPerClass(*numberDaysPerClass);
    this->setDegreeProgram(degreeProgram);
    this->setEmailIsValid(mailIsValid(email));
    
}

Student::Student(string nullStudent) { //return NULL record (for errors)
    this->setStudentID("NULL");
    this->setFirstName("NULL");
    this->setLastName("NULL");
    this->setEmail("NULL");
    this->setAge(0);
    this->setNumberDaysPerClass(nullptr);
    this->setDegreeProgram(SOFTWARE);
    this->setEmailIsValid(false);

}
string degreeToStr(const DegreeProgram degree) {
    if (degree == SECURITY) {
        return "SECURITY";
    }
    else if (degree == NETWORK) {
       return "NETWORK";
    }
    else if (degree == SOFTWARE) {
       return "SOFTWARE";
    }
   else return "SECURITY";
}

void Student::print() {
    std::cout << getStudentID() << "\t";
    std::cout << "First Name: " << getFirstName() << "\t";
    std::cout << "Last Name: " << getLastName() << "\t";
    std::cout << "Age: " << getAge() << "\t";
    std::cout << "daysInCourse: " << "{" << getDaysInCourse()[0] << ", ";
    std::cout << getDaysInCourse()[1] << ", ";
    std::cout << getDaysInCourse()[2] << "}\t";
    std::cout << "Degree Program: " << degreeToStr(getDegreeProgram()) << "\n";

}
void Student::printEmail() {
    std::cout << getStudentID() << "\t";
    std::cout << "First Name: " << getFirstName() << "\t";
    std::cout << "Last Name: " << getLastName() << "\t";
    std::cout << "invalid e-mail: " << getEmail() << "\n";
    
}