#include <iostream>
#include "course.h"
using namespace std;

Course::Course(string name, int num) {
	course_name = name;
	unit = num;
}

void Course::getRoster(string name) {
	for (int num = 0; num < 300; num++) {
		this->roster.addStudent(name);
		return;
	}
}

string Course::get_coursename() {
	return course_name;
}

void Course::print() {
	cout << "Course Name: " << course_name << endl;
	cout << "Number of units: " << unit << endl;
	roster.print();
	cout << endl;
}