#include <iostream>
#include<vector>
#include "schedule.h"
using namespace std;

void Schedule::addCourse(string name) {
	for (int value = 0; value < 10; value++) {
		this->names.push_back(name);
		return;
	}
}

void Schedule::print() {
	cout << "List of Courses: " << endl;
	for (string elem : names) {
		cout << elem <<  endl;
	}
}