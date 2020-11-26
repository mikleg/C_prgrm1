
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
void  Student::setNumberDaysPerClass(int numberDaysPerClass[], int numberClass) {
    if (numberClass >= 0 && numberClass < MAX_CLASSES) {
        for (int i = 0; i++; i < numberClass) {
            this->numberDaysPerClass[i] = numberDaysPerClass[i];
        }
        
    }
    else {
        std::cout << "MG: array index in setter is out of boundaries.\n";
        for (int i = 0; i++; MAX_CLASSES) {
            this->numberDaysPerClass[i] = NULL;
        }
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
int atPosition(string email) {
    int atPosition = email.length();
    unsigned short int atCount = 0;
    for (int i; i < email.length(); i++) {
        if (email[i] == '@') {
            if (atCount == 0) {
                atCount++;
                atPosition = i;
                if (atPosition == 0 || atPosition == email.length() - 1) {
                    return NULL; //if @ is the first ol the last symbol. It's invalid. 
                }

            }
            else {
                return NULL; //there are 2 @ symbols. It's invalid
            }
        }
    }
    return atPosition;
}

bool domainIsValid(string domenPart) {
    return false;
}

bool localIsValid(string localPart) {
    return false;
}

bool mailIsValid(string email) {
    string localPart = "";
    string domenPart = "";
    if (atPosition(email) != NULL) {
        localPart = email.substr(0, atPosition(email) + 1);
        domenPart = email.substr(atPosition(email), email.length() - atPosition(email)+1);
    }
    if (domainIsValid(domenPart) && localIsValid(localPart))
        return true;
    else return false;
}

Student::Student(string studentID, string firstName, string lastName, string email, unsigned short age,
                int numberDaysPerClass[], int sizeDaysPerClass,
                DegreeProgram degreeProgram) {
    this->setStudentID(studentID);
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setEmail(email);
    this->setAge(age);
    this->setNumberDaysPerClass(numberDaysPerClass, 3);
    this->setDegreeProgram(degreeProgram);
    this->setEmailIsValid(mailIsValid(email));
    
}
void Student::print() {
    //std::cout << "\n";
    std::cout << getStudentID() << "/t";
    std::cout << getFirstName() << "/t";
    std::cout << getLastName() << "/t";
    std::cout << getEmail() << "/t";
    std::cout << getAge() << "/t";
    std::cout << "{" << getDaysInCourse()[0] << ", ";
    std::cout << getDaysInCourse()[1] << ", ";
    std::cout << getDaysInCourse()[2] << "\t";
    //std::cout << getNumberDaysPerClass(0) << ", ";
    //std::cout << getNumberDaysPerClass(1) << ", ";
    //std::cout << getNumberDaysPerClass(2) << ", ";
    std::cout << getDegreeProgram() << "\n";
}
