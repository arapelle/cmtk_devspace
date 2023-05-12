#pragma once 

#include <string>

inline namespace cmtk_tests
{
namespace cpp_hutil
{

inline std::string module_name() { return "cpp_hutil"; }

inline int compute(int first, int second)
{
    return first * second;
}

}
}
