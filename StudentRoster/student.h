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
	
		
	

		
};

