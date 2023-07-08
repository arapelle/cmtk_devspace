#include <iostream>
#include <cmtk_tests/alpha/alpha.hpp>
#include <cmtk_tests/alpha/version.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    std::cout << alphabet::alpha::module_name() << std::endl;
    std::cout << cmtk_tests::alphabet::alpha::module_name() << " " << CMTK_TESTS_ALPHA_VERSION << std::endl;
    return EXIT_SUCCESS;
}
