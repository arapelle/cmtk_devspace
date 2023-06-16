#pragma once 

#include <string>

#ifndef SPDLOG_ACTIVE_LEVEL 
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

namespace lymerenide
{

std::string module_name();
int compute(int first, int second);

}
