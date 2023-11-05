
#ifndef REGISTER_H_
#define REGISTER_H_

#include <iostream>
#include <vector>

#include "student.h"
#include "course.h"

using namespace std;

class Register {
public:
	void enroll(Student& student, Course& course);
};

#endif