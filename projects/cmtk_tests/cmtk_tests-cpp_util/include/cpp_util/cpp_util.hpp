#pragma once 

#include <string>

#ifndef SPDLOG_ACTIVE_LEVEL 
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

inline namespace cmtk_tests
{
namespace cpp_util
{

std::string module_name();
int compute(int first, int second);

}
}
