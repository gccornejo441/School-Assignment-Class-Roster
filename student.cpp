#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(string XstudentID, string XfirstName, string XlastName, string XemailAddress, int Xage,
	int XdaysInCourse[3], DegreeProgram XdegreeProgram)
{
	studentID = XstudentID;
	firstName = XfirstName;
	lastName = XlastName;
	emailAddress = XemailAddress;
	age = Xage;
	for (int i = 0; i < 3; i++) {
		courseDays[i] = XdaysInCourse[i];
	}
	degreeProgram = XdegreeProgram;
}

//Destructor
Student::~Student()
{
}

string Student::GetStudentID()
{
	return studentID;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}

string Student::GetEmailAddress()
{
	return emailAddress;
}

int Student::GetAge()
{
	return age;
}

int* Student::GetDaysInCourse()
{
	return courseDays;
}

DegreeProgram Student::GetDegreeProgram()
{
	return degreeProgram;
}

string Student::GetDegreeProgram(string str)
{
	if (degreeProgram == SECURITY) {
		return "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		return "NETWORK";
	}
	else {
		return "SOFTWARE";
	}
}

float Student::GetAverageDaysInCourses()
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += courseDays[i];
	}
	float totalDays = 3;
	return sum / totalDays;
}


// Setters
void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}


void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}


void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}


void Student::SetEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

int Student::emailValidation()
{
	if (emailAddress.find("@") == string::npos || emailAddress.find(".") == string::npos || emailAddress.find(" ") != string::npos) { // no "@" found
		return 1;
	}
	return 0;
}


void Student::SetAge(int age)
{
	this->age = age;
}


void Student::SetDaysInCourse(int* XdaysInCourse)
{
	for (int i = 0; i < 3; i++) {
		courseDays[i] = XdaysInCourse[i];
	}

}

void Student::SetDaysInCourse(int index, int days)
{
	courseDays[index] = days;
}


void Student::SetDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::print()
{
	int i = 0;
	string degreeOption = "";
	cout << studentID;
	cout << "\t" << "First Name: " << firstName;
	cout << "\t" << "Last Name: " << lastName;
	cout << "\t" << "Age: " << age;
	cout << "\t" << "daysInCourse: {" << "\t";
	cout << courseDays[i];
	for (int i = 1; i < courseLimit; i++) {
		cout << ", " << courseDays[i];
	}
	cout << " }\tDegree Program: " << GetDegreeProgram(degreeOption) << "." << endl;
}
