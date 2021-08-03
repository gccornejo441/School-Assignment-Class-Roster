#pragma once

#include "student.h"

using namespace std;

class Roster
{
public: 
	Roster(); // Default constructor
	
	~Roster(); // Destructor

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);

	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram);
	void printByDegreeProgram();

	string getSID(int studentNo);

private:
	const int sizeOfRoster = 5;
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};
