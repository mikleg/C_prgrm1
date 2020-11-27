
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
    /*if (numberClass >= 0 && numberClass < MAX_CLASSES) {
        for (int i = 0; i++; i < numberClass) {
            this->numberDaysPerClass[i] = numberDaysPerClass[i];
        }
        
    }
    else {
        std::cout << "MG: array index in setter is out of boundaries.\n";
        for (int i = 0; i++; MAX_CLASSES) {
            this->numberDaysPerClass[i] = NULL;
        }
    }*/
    //int tempArray[3] = {20, 30, 40};
    int debug3 = MAX_CLASSES;
    for (int i = 0; i < MAX_CLASSES;  i++) {
        int debug2 = 0;
        this->numberDaysPerClass[i] = localNumberDaysPerClass[i];
        debug2 = 2;
    }

}
//void  Student::setNumberDaysPerClass(int numberDaysPerClass[], int numberClass) {
//    if (numberClass >= 0 && numberClass < MAX_CLASSES) {
//        this->numberDaysPerClass[numberClass] = numberDaysPerClass;
//    }
//    else {
//        std::cout << "MG: array index in setter is out of boundaries.\n";
//        for (int i = 0; i++; MAX_CLASSES) {
//            this->numberDaysPerClass[i] = NULL;
//        }
//    }
//}
int symbPosition(string str, string symbol) {
    if (str.find(symbol) == str.rfind(symbol)
        && str.find(symbol) > 0
        && str.find(symbol) < str.length() - 1) { //if last find = first -> we have only one such symbol
        return str.find(symbol);
    }
    else return NULL;
}

bool domainIsValid(string domenPart) {
    if (symbPosition(domenPart, ".") != NULL) { //if we have . and it is not first and last 
        for (int i=0; i < domenPart.length(); i++) {
            if (!isalnum(domenPart[i]) && domenPart[i] != '.') {
                return false;
            }
        }
    }
    else return false;
    return true;
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
        localPart = email.substr(0, symbPosition(email, "@") + 1);
        domenPart = email.substr(symbPosition(email, "@"), email.length() - symbPosition(email, "@") +1);
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
void Student::print() {
    std::cout << getStudentID() << "\t";
    std::cout << getFirstName() << "\t";
    std::cout << getLastName() << "\t";
    std::cout << getEmail() << "\t";
    std::cout << getAge() << "\t";
    std::cout << "{" << getDaysInCourse()[0] << ", ";
    std::cout << getDaysInCourse()[1] << ", ";
    std::cout << getDaysInCourse()[2] << "\t";
    std::cout << getDegreeProgram() << "\n";
}
