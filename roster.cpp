#include <iostream>
#include <string>

#include "roster.h"

using namespace std;


Roster::Roster()
{
}

Roster::~Roster()
{
	int i = 0;
	for (i = 0; i < sizeOfRoster; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int numDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < sizeOfRoster; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeProgram);
			break;
		}
	}
}


void Roster::remove(string studentID)
{
	bool studentError = false;
	for (int i = 0; i < sizeOfRoster; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				studentError = true;
			}
		}
	}
	if (studentError == false) {
		cout << "ERROR - Student: " << studentID << " not found." << endl;
	}
}

void Roster::printAll()
{
	for (int i = 0; i < sizeOfRoster; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	// E3d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a 
	// student’s average number of days in the three courses.The student is identified by
	// the studentID parameter.

	int stuIDX;

	for (int i = 0; i < sizeOfRoster; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			stuIDX = i;
		}
	}
	cout << "Student " << classRosterArray[stuIDX]->GetStudentID() << " "
		<< " has averaged "
		<< classRosterArray[stuIDX]->GetAverageDaysInCourses()
		<< " day(s) per course for the last three courses." << endl;
}

void Roster::printInvalidEmails()
{
	// E3e.  public void printInvalidEmails() that verifies student email addresses and
	// displays all invalid email addresses to the user.
	int i = 0;
	cout << "Invalid email addresses:" << endl;
	for (i = 0; i < sizeOfRoster; i++) {
		if (classRosterArray[i]->emailValidation() == 1) {
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram byDegreeProgram)
{
	for (int i = 0; i < sizeOfRoster; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == byDegreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printByDegreeProgram()
{
	int j = 0;
	for (int i = 0; i < sizeOfRoster; i++) {
		for (j = 0; j < sizeOfRoster; j++) {
			if (classRosterArray[i]->GetDegreeProgram() == NETWORK) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < sizeOfRoster; j++) {
			if (classRosterArray[i]->GetDegreeProgram() == SECURITY) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < sizeOfRoster; j++) {
			if (classRosterArray[i]->GetDegreeProgram() == SOFTWARE) {
				classRosterArray[i]->print();
			}
		}
	}
}

string Roster::getSID(int studentNo)
{
	return classRosterArray[studentNo]->GetStudentID();
}
