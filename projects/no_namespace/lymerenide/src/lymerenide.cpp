#include <lymerenide/lymerenide.hpp> 
#include <spdlog/spdlog.h>

namespace lymerenide
{

std::string module_name()
{
    return "lymerenide";
}

int compute(int first, int second)
{
    SPDLOG_TRACE("{}::compute({}, {})", module_name(), first, second);
    return first * second;
}

}
