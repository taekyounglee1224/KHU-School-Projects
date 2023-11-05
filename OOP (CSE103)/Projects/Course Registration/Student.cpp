#include <iostream>
#include "student.h"
using namespace std;

Student::Student(string name) {
	std_name = name;
}
void Student::getSchedule(string name) {
	schedule.addCourse(name);
	return;
}

string Student::get_stdname() {
	return std_name;
}

void Student::print() {
	cout << "Student Name: " << std_name<< endl;
	schedule.print();
	cout << endl;

}