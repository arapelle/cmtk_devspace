#include <iostream>
#include <cmtk_tests/cpp_util/cpp_util.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    std::cout << cpp_util::module_name() << std::endl;
    std::cout << cpp_util::compute(6, 7) << std::endl;
    return EXIT_SUCCESS;
}
