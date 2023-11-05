#include <iostream>
#include "roster.h"
using namespace std;

Roster::Roster() {

}

void Roster::addStudent(string name) {
	this->names.push_back(name);
	return;
}

void Roster :: print() {
	cout << "List of students: " << endl;
	for (string elem : names) {
		cout << elem << endl;
	}
}

