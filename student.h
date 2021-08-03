#pragma once

#include "Degree.h"

using namespace std;


class Student
{
public:
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* courseDays, DegreeProgram degreeProgram);
	
	//Destructor
	~Student();

	//Mutators
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();

	int GetAge();

	string GetDegreeProgram(string str);
	DegreeProgram GetDegreeProgram();

	int* GetDaysInCourse();
	float GetAverageDaysInCourses();

	//Accessors
	void SetDegreeProgram(DegreeProgram degreeProgram);
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetAge(int age);
	void SetDaysInCourse(int* daysInCourseVal);
	void SetDaysInCourse(int index, int days);
	void print();

	void SetEmailAddress(string emailAddress);
	int emailValidation();

private:
	const int courseLimit = 3;
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[3] = {};
	DegreeProgram degreeProgram;
};