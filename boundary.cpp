#include "boundary.h"
#include <stdexcept>
#include <sstream>
using std::ifstream;
using std::domain_error;
using std::ofstream;
using std::endl;
using std::cout;
using std::cin;
using std::exception;
using std::string;

std::istream& operator>>(std::istream& in, Grade& g)
{
    string str = "";
    while (in && str.empty()) {
        std::getline(in, str);
    }
    if (in) {
        std::stringstream sstr(str);
        g.m_homeworks.clear();
        double x;
        while (sstr >> x) {
            g.m_homeworks.push_back(x);
        }
        if (g.m_homeworks.empty()) {
            throw domain_error("发生错误，数据不完整\n");
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Grade& g)
{
    out << g.m_name << std::string((20 - g.nameSize()), ' ') << g.score() << std::endl;
    return out;
}

void outputCourseGrades(Course& course)
{
    ofstream ofs("../projects21/score.dat");
    if (!ofs.is_open()) {
        cout << "输出文件打开失败\n";
        exit(1);
    }
    for (auto& g : course._grades) {
        ofs << *g; // 将学生成绩输出到文件中
    }
}

void readCourseGrades(Course& course, std::string path)
{
    ifstream ifs("../projects21/" + path);
    if (!ifs.is_open()) {
        //        cout << path << std::endl;
        cout << "文件打开失败\n";
        exit(1);
    }
    try {
        // 这边应该new一个新的Grade对象
        // 动态开辟内存
        while (1) {
            string name;
            double x, y;
            ifs >> name >> x >> y;
            Grade* g = new Grade(name,x,y);   //这边调用其构造函数
            ifs >> *g;
            if (!ifs) {
                break;
            }
            course._grades.push_back(g);
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    if (course._grades.empty()) {
        throw domain_error("读取信息失败");
    }
}





