#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

using std::string;
using std::cout;
using std::endl;

//CONSTRUCTOR
Roster::Roster() {
	this -> max_students = 0;
	this -> classRosterArray = nullptr;
	this -> number_students = 0;
}

Roster::Roster(int max_students) {
	this -> max_students = max_students;
	this -> classRosterArray =  new Student * [max_students];
	this -> number_students = 0;
}

//SPLIT STRING THEN ADD STUDENT
void Roster::parse_string_input(string raw_data_string) {
	if (number_students <= max_students) {
		number_students++;

		Degree degree_type;

		int num_str_split = 9;
		int str_split_start = 0;
		int str_split_end = 0;
		string list_str_split[9];

		for (int i = 0; i < num_str_split ; i++) {
			str_split_end = raw_data_string.find("," , str_split_start);
			list_str_split[i] = raw_data_string.substr(str_split_start, str_split_end - str_split_start);
			str_split_start = str_split_end + 1;
		}

		string student_ID = list_str_split[0];
		string first_name = list_str_split[1];
		string last_name = list_str_split[2];
		string email_address = list_str_split[3];
		int age = stoi(list_str_split[4]);
		int days_in_course1 = stoi(list_str_split[5]);
		int days_in_course2 = stoi(list_str_split[6]);
		int days_in_course3 = stoi(list_str_split[7]);


		if (list_str_split[8] == "NETWORK") {
			degree_type = NETWORKING;
		}

		else if (list_str_split[8] == "SECURITY") {
			degree_type = SECURITY;
		}

		else if (list_str_split[8] == "SOFTWARE") {
			degree_type = SOFTWARE;
		}

		else {
			cout << "NO VALID DEGREE TYPE FOUND. EXITING PROGRAM. \n";
			exit(1);

		}
		add_student(student_ID, first_name, last_name, email_address, age, days_in_course1, days_in_course2, days_in_course3, degree_type);


	}

	else {
		cout << "Maximum allowed students exceeded. Ending program.\n";
		exit(1);
	}
}

//GET STUDENT ID VIA INDEX
Student* Roster::get_student(int index) {
	return classRosterArray[index];
}


//HOW TO ADD STUDENT
void Roster::add_student
	(string student_ID,
	string first_name,
	string last_name,
	string email_address,
	int age,
	int days_in_course1,
	int days_in_course2,
	int days_in_course3,
	Degree degree_type)
{
	int days_to_complete[Student::days_array_size];
	days_to_complete[0] = days_in_course1;
	days_to_complete[1] = days_in_course2;
	days_to_complete[2] = days_in_course3;

		if (degree_type == NETWORKING) {
			classRosterArray[number_students - 1] = new networkStudent(
				student_ID,
				first_name,
				last_name,
			    email_address,
				age,
				days_to_complete,
				degree_type);
		}

		else if (degree_type == SECURITY) {
			classRosterArray[number_students - 1] = new securityStudent(
				student_ID,
				first_name,
				last_name,
				email_address,
				age,
				days_to_complete,
				degree_type);
		}

		else {
			classRosterArray[number_students - 1] = new softwareStudent(
				student_ID,
				first_name,
				last_name,
				email_address,
				age,
				days_to_complete,
				degree_type);
		}
};

//HOW TO REMOVE STUDENT
void Roster::removeStudent(string student_ID) {
	for (int i = 0; i < number_students; i++) {
		if (this -> classRosterArray[i] -> getStudentID() == student_ID) {
			cout << this -> classRosterArray[i]->getStudentID() << " has been removed permanently!\n";
			delete this -> classRosterArray[i];
			classRosterArray[i] = classRosterArray[number_students - 1];
			number_students--;
			return;
		}
	}

	cout << "NO STUDENT WITH THE ID " << student_ID << " FOUND \n";
	return;
	
}

//PRINT ALL
void Roster::printAll() {
	for (int i = 0; i < number_students; i++) {
		this -> classRosterArray[i] -> print();

	}
}

//PRINT DAYS IN COURSE
void Roster::printDaysInCourse(string student_ID) {
	for (int i = 0; i <  number_students; i++) {
		if (this -> classRosterArray[i] -> getStudentID() == student_ID) {
			int* list_to_average = this -> classRosterArray[i] -> getDaysToComplete();
			cout << "AVERAGE OF DAYS TO COMPLETE BY " << this -> classRosterArray[i] -> getStudentFirstName() << " " << this-> classRosterArray[i] -> getStudentLastName()  << " IS " << (list_to_average[0] + list_to_average[1] + list_to_average[2]) / 3 << endl;
			return;
		}
	}
	return;
}

//PRINT INVALID EMAILS
void Roster::printInvalidEmails() {
	for (int i = 0; i < number_students; i++) {
		bool invalid = false;
		string email = this -> classRosterArray[i] -> getStudentEmail();
		if (email.find(" ") != -1) {
			invalid = true;
		}

		if (email.find("@") == -1) {
			invalid = true;
		}

		if (email.find(".") == -1) {
			invalid = true;
		}

		if (invalid == true) {
			cout << "'" <<  this -> classRosterArray[i] -> getStudentEmail() << "' IS NOT A VALID EMAIL. \n";
		}

	}
}

//PRINT ALL MEMBERS OF DEGREE PROGRAM
void Roster::printByDegreeProgram(Degree degree_program) {
	for (int i = 0; i < number_students; i++) {
		if (this -> classRosterArray[i] -> get_degree_program() == degree_program) {
			this -> classRosterArray[i] -> print();
		}
	}
}

//DESTRUCTORATOR
Roster::~Roster() {
	for (int i = 0; i < number_students; i++) {
		delete this -> classRosterArray[i];
	}
	delete classRosterArray;
}

int main() {
	cout << "---------------------------------------------------------------------------------- \n";
	cout << "**********Scripting and Programming - Applications | Student Roster in C++******** \n";
	cout << "*****************AUTHORED BY: JUSTIN HODGE WGU STUDENT ID 001108282*************** \n";
	cout << "---------------------------------------------------------------------------------- \n\n\n";

	int number_students = 5;

	//THIS IS STUDENT DATA
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Justin,Hodge,jhodg98@wgu.edu,29,35,39,19,SOFTWARE" };

	//MAKE STUDENTS
	cout << "****************************MAKING AND DISPLAYING STUDENTS***************************\n";
	Roster* classRoster = new Roster(number_students);

	//ADD STUDENTS TO ROSTER
	for (int i = 0; i < number_students; i++) {
		classRoster -> parse_string_input(studentData[i]);
	}

	//STUFF THEY WANT ME TO DEMONSTRATE

	//PRINT ALL TEH THINGS
	classRoster -> printAll();
	cout << "------------------------------------------------------------------------------------\n\n\n";

	//WHO IS INVALID EMAILS
	cout << "*************************THESE EMAILS ARE INVALID. PLEASE ADJUST********************\n";
	classRoster -> printInvalidEmails();
	cout << "------------------------------------------------------------------------------------\n\n\n";

	//AVERAGE DAYS IN COURSES
	cout << "*********************************AVERAGE OF LISTED DAYS*****************************\n";
	for (int i = 0; i < number_students; i++) {
		classRoster -> printDaysInCourse(classRoster -> get_student(i) -> getStudentID());
	}
	cout << "------------------------------------------------------------------------------------\n\n\n";

	//ALL THE SOFTWARE BOYS
	cout << "**************************THESE STUDENTS ARE IN THE SOFTWARE PROGRAM****************\n";
	classRoster -> printByDegreeProgram(SOFTWARE);
	cout << "------------------------------------------------------------------------------------\n\n\n";

	//REMOVE A3
	cout << "*******************************REMOVING STUDENTS************************************\n";
	classRoster -> removeStudent("A3");

	//REMOVE A3 AGAIN FOR GOOD MEASURE
	classRoster -> removeStudent("A3");
	cout << "------------------------------------------------------------------------------------\n\n\n";
	//RELEASE THE KRAKEN.... OR AT LEAST THE MEMORY
	classRoster -> ~Roster();

	return 0;

}