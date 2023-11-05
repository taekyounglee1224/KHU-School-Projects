
#ifndef ROSTER_H_
#define ROSTER_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Roster{
private:
	vector<string> names;
public:
	Roster();
	void addStudent(string name);
	void print();

};
#endif
