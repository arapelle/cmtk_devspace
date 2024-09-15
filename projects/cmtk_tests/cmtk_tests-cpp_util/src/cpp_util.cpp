#include <cmtk_tests/cpp_util/cpp_util.hpp> 
#include <spdlog/spdlog.h>

inline namespace cmtk_tests
{
namespace cpp_util
{

std::string module_name()
{
    return "cpp_util";
}

int compute(int first, int second)
{
    SPDLOG_INFO("{}::compute({}, {})", module_name(), first, second);
    return first * second;
}

}
}
