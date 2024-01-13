#ifndef STUDENT_H
#define STUDENT_H
#include "grade.h"

class Student {
public:
private:
    std::string m_name; // 学生名字
    std::vector<Grade*> _grades;    //一个存放学生多门课程成绩的数组


};

#endif // STUDENT_H
