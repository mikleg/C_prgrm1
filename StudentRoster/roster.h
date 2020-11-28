#include "student.h"
class Roster{
private:
	static const int MAX_STUDENTS = 10000;
	int currentNumStudents ;
	Student* classRosterArray[MAX_STUDENTS];
public:
	//constructors
	Roster();
	Roster(const string dataArray[], size_t size);
	~Roster() {	}
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		 int numberDaysPerClass[3], DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(const DegreeProgram degreeProgram);
	int getCurrentNumStudents() {return currentNumStudents;}
	Student getStudentByNumber(const int number);
	DegreeProgram degreeParser(const string str);
};

