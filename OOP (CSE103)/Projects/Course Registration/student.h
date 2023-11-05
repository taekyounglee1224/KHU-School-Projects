
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <vector>
#include <string>

#include "schedule.h"

class Student{
private: 
	string std_name;
	Schedule schedule;
public:
	Student(string name);
	void getSchedule(string name);
	string get_stdname();
	void print();
};

#endif