#include "securityStudent.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

securityStudent::securityStudent() :Student() {
	degree_type = NETWORKING;
}

securityStudent::securityStudent
	(string new_student_ID,
	string new_first_name,
	string new_last_name,
	string new_email,
	int new_age,
	int days_to_complete[],
	Degree new_degree_type) : Student(new_student_ID, new_first_name, new_last_name, new_email, new_age, days_to_complete) {
	degree_type = SECURITY;
}

Degree securityStudent::get_degree_program() {
	return degree_type;
}

void securityStudent::print() {
	this->Student::print();
	cout << list_of_degrees[get_degree_program()] << endl;
}

securityStudent::~securityStudent() {
	Student::~Student();
}