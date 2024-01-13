#include "utils.h"

#include <stdexcept>
using std::domain_error;

#include <algorithm>
using std::sort;

using std::string;

// 得到家庭作业的中位数

double median(std::vector<double> vec)
{
    auto size = vec.size();
    if (size == 0)
        throw domain_error { "求中值遇到一个空的vector" };
    sort(vec.begin(), vec.end());

    auto mid { size / 2 };
    if (size % 2 == 0)
        return (vec[mid] + vec[mid - 1]) / 2;
    else
        return vec[mid];
}

bool is_EmptyOrWhitespace(const std::string str){
    return str.empty() || std::all_of(str.begin(), str.end(), [](unsigned char c) { return std::isspace(c); });
}
