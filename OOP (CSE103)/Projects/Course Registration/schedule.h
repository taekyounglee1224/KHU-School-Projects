
#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Schedule{
private:
	vector<string> names;
public:
	int value;
	void addCourse(string name);
	void print();
};

#endif
