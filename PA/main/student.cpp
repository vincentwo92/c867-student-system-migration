#include <iostream>
#include "student.h"

string degreeProgramToString(DegreeProgram degreeProgram) {
	switch (degreeProgram) {
	case SECURITY:
		return "SECURITY";
	case NETWORK:
		return "NETWORK";
	case SOFTWARE:
		return "SOFTWARE";
	}
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, vector<int> courseDays, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->courseDays = courseDays;
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
vector<int> Student::getCourseDays() { return courseDays; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setCourseDays(vector<int> courseDays) { this->courseDays = courseDays; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() {
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << age << "\t";
	cout << "Email: " << email << "\t";
	cout << "daysInCourse: {";
	
	for (int i = 0; i < courseDays.size(); i++) {
		if (i != courseDays.size() - 1) { cout << courseDays.at(i) << ", "; }
		else { cout << courseDays.at(i) << "} " << "\t"; }
	}
	
	cout << "Degree Program: " << degreeProgramToString(degreeProgram) << "\t";
	cout << "." << endl;
}