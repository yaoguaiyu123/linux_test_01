//Author:WuBoyuan
//Date:2023/12/05
//Introduce:这是一个计算学生成绩的程序

#include <iostream>
#include "boundary.h"
// 一个问题:友元函数声明的时候，是不是需要全局函数的声明
using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string filePath;
    cout << "请输入数据文件地址\n";
    cin >> filePath;
    Course sci("汉语言课");
    readCourseGrades(sci, filePath);
    sci.sortByScore();
    outputCourseGrades(sci);
    return 0;
}
