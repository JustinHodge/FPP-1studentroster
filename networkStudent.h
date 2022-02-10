#pragma once
#include "student.h"

class networkStudent : public Student {

public: 
	networkStudent();
	networkStudent(
		string new_student_ID,
		string new_first_name, 
		string new_last_name, 
		string new_email, 
		int new_age, 
		int days_to_complete[],
		Degree new_degree_type

	);

	Degree get_degree_program();

	void print();

	~networkStudent();

};