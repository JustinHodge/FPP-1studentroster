#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
public:
	const static int days_array_size = 3;

protected:
	string student_ID;
	string first_name;
	string last_name;
	string email;
	int age;
	int days_to_complete[days_array_size];
	Degree degree_type;

public:


	//accessors
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	int getAge();
	int* getDaysToComplete();

	//mutators
	void setStudentID(string update_student_ID);
	void setStudentFirstName(string update_first_name);
	void setStudentLastName(string update_last_name);
	void setStudentEmail(string update_email);
	void setAge(int update_age);
	void setDaysToComplete(int update_days[]);

	virtual void print() = 0;

	virtual Degree get_degree_program() = 0;

	//constructor
	Student();
	Student(string new_student_ID, string new_first_name, string new_last_name, string new_email, int new_age, int days_to_complete[]);

	//destructor
	~Student();
};