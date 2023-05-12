#include <cpp_exe/cpp_exe.hpp> 
#include <spdlog/spdlog.h>
#include <iostream>
#include <cstdlib>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    SPDLOG_DEBUG("Begin");
    SPDLOG_INFO("Printing cmtk_tests::cpp_exe::module_name(): {}", cmtk_tests::cpp_exe::module_name());
    SPDLOG_INFO("Printing cpp_exe::module_name(): {}", cmtk_tests::cpp_exe::module_name());
    SPDLOG_DEBUG("End");
    return EXIT_SUCCESS;
}
