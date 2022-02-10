#include "student.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


//getters

string Student::getStudentID() {
	return student_ID;
}

string Student::getStudentFirstName() {
	return first_name;
}

string Student::getStudentLastName() {
	return last_name;
}

string Student::getStudentEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysToComplete() {
	return days_to_complete;
}
//setters

void Student::setStudentID(string new_student_ID) {
	this -> student_ID = new_student_ID;
}

void Student::setStudentFirstName(string new_student_first_name) {
	this -> first_name = new_student_first_name;
}

void Student::setStudentLastName(string new_student_last_name) {
	this -> last_name = new_student_last_name;
}

void Student::setStudentEmail(string new_email) {
	this -> email = new_email;
}

void Student::setAge(int new_age) {
	this -> age = new_age;
}

void Student::setDaysToComplete(int days_to_complete[]) {
	for (int i = 0; i < days_array_size; i++) {
		this -> days_to_complete[i] = days_to_complete[i];
	}
}

//virtual print

void Student::print() {
	cout << "Student ID: " << getStudentID() << "\t";
	cout << "Student Name: " << getStudentFirstName() << " " << getStudentLastName() << "\t";
	cout << "Student Email: " << getStudentEmail() << "\t";
	cout << "Student Age: " << getAge() << "\t";
	cout << "Days Taken for 3 Courses: " << getDaysToComplete()[0] << "," << getDaysToComplete()[1] << "," << getDaysToComplete()[2] << "\t";
}

//constructor

Student::Student() {
	student_ID = "XX";
	first_name = "NULL";
	last_name = "NULL";
	email = "NULl";
	age = 0;
	for (int i = 0; i < days_array_size; ++i) {
		this -> days_to_complete[i] = 0;
	}
}

Student::Student(string new_student_ID, string new_first_name, string new_last_name, string new_email, int new_age, int days_to_complete[] ) {
	this -> student_ID = new_student_ID;
	this -> first_name = new_first_name;
	this -> last_name = new_last_name;
	this -> email = new_email;
	this -> age = new_age;
	for (int i = 0; i < days_array_size; ++i) {
		this -> days_to_complete[i] = days_to_complete[i];
	}
}

//destructor
Student::~Student() {

}
