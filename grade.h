#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Grade {
public:
    //声明运算符重载的全局函数为当前类的友元函数，友元函数能够访问私有成员
    friend std::istream& operator>>(std::istream& in, Grade& g);
    friend std::ostream& operator<<(std::ostream& out, Grade& g);
    double score() const;     //得出最终成绩的函数
    std::string::size_type nameSize()
    {
        return m_name.size(); // 返回名字的长度
    }
    Grade(std::string name, double midterm, double final);

private:
    std::string m_name;
    double m_midterm;
    double m_final;
    std::vector<double> m_homeworks;

};


#endif // GRADE_H
