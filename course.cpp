#include "course.h"
#include <algorithm>


// 内部链接性
namespace {
bool compareByScore(const Grade* g1, const Grade* g2)
{
    return g1->score() > g2->score();
}
}


void Course::sortByScore()
{
    // ::引用内部连接性的变量或者全局变量\
    int a =1;
    int b = 2;
    std::sort(_grades.begin(), _grades.end(), ::compareByScore);
}


Course::Course(std::string name)
    : m_name(name)
{
    ;
}

Course::~Course()
{
    //在析构函数中释放堆内存
    for (auto& g : _grades)
    {
        delete g; // 输出完之后将动态开辟的内存释放
        g = nullptr;
    }
}
