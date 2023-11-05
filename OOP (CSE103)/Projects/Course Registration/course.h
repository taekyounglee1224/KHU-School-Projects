
#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <vector>
#include <string>
#include "roster.h"
using namespace std;

class Course{
private:
	int unit;
	string course_name;
	Roster roster;
public:
	Course(string name, int num);
	void getRoster(string name);
	string get_coursename();
	void print();
};
#endif

