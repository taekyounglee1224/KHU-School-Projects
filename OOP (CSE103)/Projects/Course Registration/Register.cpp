#include <iostream>
#include "register.h"
using namespace std;

void Register::enroll(Student& student, Course& course) {
	course.getRoster(student.get_stdname());
	student.getSchedule(course.get_coursename());
	return;
}
