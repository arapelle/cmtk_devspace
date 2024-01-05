#pragma once 

#include <string>

inline namespace cmtk_tests
{
namespace cpp_htool
{

inline std::string module_name() { return "cpp_htool"; }

inline int compute(int first, int second)
{
    return first * second;
}

}
}
