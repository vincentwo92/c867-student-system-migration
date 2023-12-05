#include <iostream>
#include <sstream>
#include <regex>
#include "roster.h"

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	vector<int> courseDays;
	courseDays.push_back(daysInCourse1);
	courseDays.push_back(daysInCourse2);
	courseDays.push_back(daysInCourse3);

	classRosterArray.push_back(new Student(studentID, firstName, lastName, email, age, courseDays, degreeProgram));
}

void Roster::remove(string studentID) {
	int n = -1;
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (classRosterArray.at(i)->getStudentID() == studentID) { n = i; }
	}
	
	if (n > 0) {
		Student* studentToDelete = classRosterArray.at(n);
		classRosterArray.erase(classRosterArray.begin() + n); 
		delete studentToDelete;
		cout << "Successfully removed" << studentID << "." << endl;
	}
	else { cout << "Student with ID " << studentID << " not found." << endl; }
}

void Roster::printAll() {
	for (int i = 0; i < classRosterArray.size(); i++) { classRosterArray.at(i)->print(); }
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (classRosterArray.at(i)->getStudentID() == studentID) {
			vector<int> courseDays = classRosterArray.at(i)->getCourseDays();
			int average = (courseDays.at(0) + courseDays.at(1) + courseDays.at(2)) / 3;
			cout << studentID << " average days in courses: " << average << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "Invalid email addresses:" << endl;

	const regex emailPattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

	for (int i = 0; i < classRosterArray.size(); i++) {
		string email = classRosterArray.at(i)->getEmail();
		if (!std::regex_match(email, emailPattern)) {
			classRosterArray.at(i)->print();
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (classRosterArray.at(i)->getDegreeProgram() == degreeProgram) { classRosterArray.at(i)->print(); }
	}
}

Roster::~Roster() {
	for (int i = 0; i < classRosterArray.size(); i++) {
		delete classRosterArray.at(i);
		classRosterArray.at(i) = nullptr;
	}
}
