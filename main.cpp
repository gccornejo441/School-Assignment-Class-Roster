#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "roster.h"

using namespace std;

int main() {

	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "StudentID: 001681157" << endl;
	cout << "Name: Gabriel Cornejo" << endl << endl;


	const int sizeOfRoster = 5;
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Gabriel,Cornejo,gcornej@wgu.edu,26,20,20,20,SOFTWARE" }; 

	DegreeProgram degreeProgram;

	Roster classRoster;

	string studentID;

	cout << "Adding Students to Roster: ";
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string rAddDat[9];

		int j = 0;
		while (getline(ss, token, ',')) {
			rAddDat[j] = token;
			j += 1;
		}

		if (rAddDat[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (rAddDat[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (rAddDat[8] == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		else {
			return 0;
		}
		cout << "Calling add for " << rAddDat[0] << ", ";
		classRoster.add(rAddDat[0],
			rAddDat[1],
			rAddDat[2],
			rAddDat[3],
			std::stoi(rAddDat[4]),
			std::stoi(rAddDat[5]),
			std::stoi(rAddDat[6]),
			std::stoi(rAddDat[7]),
			degreeProgram);
	}
	cout << endl;

	// F4.Convert the following pseudo code to complete the rest of the  main() function:
	cout << endl << "Calling printAll():" << endl;
	classRoster.printAll();

	cout << endl << "Calling printInvalidEmails():" << endl;
	classRoster.printInvalidEmails();

	//loop through classRosterArray and for each element:
	cout << endl << "Calling printAverageDaysInCourse() for each student:" << endl;
	for (int i = 0; i < sizeOfRoster; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getSID(i));
	}

	cout << endl << "Calling printByDegreeProgram(SOFTWARE):" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl << "Calling remove(A3):" << endl;
	classRoster.remove("A3");

	cout << endl << "Calling printAll():" << endl;
	classRoster.printAll();

	cout << endl << "Calling remove(A3):" << endl;
	classRoster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.
}
