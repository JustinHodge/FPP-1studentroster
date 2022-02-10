#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

class Roster {
private: 
	Student** classRosterArray;
	int max_students;
	int number_students;
public:
	Roster();
	Roster(int max_size);

	void parse_string_input(string raw_data_string);

	void add_student(
		string student_ID,
		string first_name,
		string last_name,
		string email_address,
		int age, 
		int days_in_course1,
		int days_in_course2,
		int days_in_course3,
		Degree degree_type);

	Student* get_student(int index);

	void removeStudent(string student_ID);

	void printAll();

	void printDaysInCourse(string student_ID);

	void printInvalidEmails();

	void printByDegreeProgram(Degree degree_program);

	~Roster();
};

