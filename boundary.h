#ifndef BOUNDARY_H
#define BOUNDARY_H
#include <string>
#include <vector>
#include "course.h"

//boundary中相当于是全局函数的声明和实现

std::istream& operator>>(std::istream& in, Grade& g);
std::ostream& operator<<(std::ostream& out, Grade& g);

void outputCourseGrades(Course& course);
void readCourseGrades(Course& course, std::string path);

#endif // BOUNDARY_H
