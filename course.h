#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "grade.h"

class Course {
public:
    friend void outputCourseGrades(Course& course);
    friend void readCourseGrades(Course& course, std::string path);
    void sortByScore();
    Course(std::string name);
    ~Course();

private:
    std::vector<Grade*> _grades; // 一个存放grade*类型的数组
    std::string m_name { "sci" };    //班级的名字
};

#endif // COURSE_H
