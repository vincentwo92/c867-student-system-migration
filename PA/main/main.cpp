#include <iostream>
#include <sstream>
#include "student.h"
#include "roster.h"

const int SIZE_OF_ROSTER = 5;
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Vincent,Wong,vwong11@wgu.edu,31,6,26,13,SOFTWARE"
};

void parse(Roster& classRosterArray, string studentData) {
	stringstream ss(studentData);
	string value;

	getline(ss, value, ',');
	string studentID = value;
	getline(ss, value, ',');
	string firstName = value;
	getline(ss, value, ',');
	string lastName = value;
	getline(ss, value, ',');
	string email = value;
	getline(ss, value, ',');
	int age = stoi(value);
	getline(ss, value, ',');
	int daysInCourse1 = stoi(value);
	getline(ss, value, ',');
	int daysInCourse2 = stoi(value);
	getline(ss, value, ',');
	int daysInCourse3 = stoi(value);

	DegreeProgram degreeProgram;
	getline(ss, value, ',');
	if (value == "SECURITY") { degreeProgram = SECURITY; }
	else if (value == "NETWORK") { degreeProgram = NETWORK; }
	else if (value == "SOFTWARE") { degreeProgram = SOFTWARE; }

	classRosterArray.add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

int main()
{
	cout << "C867 C++ 011319241 Vincent Wong" << endl;

	Roster classRoster;
	for (int i = 0; i < (sizeof(studentData) / sizeof(studentData[0])); i++) {
		parse(classRoster, studentData[i]);
	}

	cout << "Printing roster: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Checking for invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Printing average days in courses for each students: " << endl;
	for (int i = 0; i < SIZE_OF_ROSTER; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Printing by degreen program (SOFTWARE): " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing student with ID(A3): " << endl;
	classRoster.remove("A3");
	cout << endl;
	
	cout << "Printing roster: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Attempting to remove student with ID(A3) again: " << endl;
	classRoster.remove("A3");
	cout << endl;

	classRoster.~Roster();
}

