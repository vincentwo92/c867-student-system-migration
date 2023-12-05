#pragma once
#include <string>
#include <vector>
#include "degree.h"
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	vector<int> courseDays;
	DegreeProgram degreeProgram;

public:
	Student(string studentID, string firstName, string lastName, string email, int age, vector<int> courseDays, DegreeProgram degreeProgram);
	~Student();

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	vector<int> getCourseDays();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setCourseDays(vector<int> courseDays);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();
};