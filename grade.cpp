#include "grade.h"
#include "utils.h"


// 常量成员函数,不会修改任何一个成员变量
double Grade::score() const
{
    return 0.2 * m_midterm + 0.4 * m_final + 0.4 * median(m_homeworks);
}

Grade::Grade(std::string name, double midterm, double final)
    : m_midterm(midterm)
    , m_final(final)
    , m_name(name)
{
    if ((final < 0) || (final > 100) || (midterm) < 0 || (midterm > 100)) {
        std::cerr << "成绩有误\n";
    }
}
