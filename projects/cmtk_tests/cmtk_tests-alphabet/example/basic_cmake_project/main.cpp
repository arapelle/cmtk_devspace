#include <iostream>
#include <cmtk_tests/alphabet/version.hpp>
#include <cmtk_tests/alpha/alpha.hpp>
#include <cmtk_tests/alpha/version.hpp>
#include <cmtk_tests/beta/beta.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    std::cout << CMTK_TESTS_ALPHABET_VERSION << std::endl;
    std::cout << alphabet::alpha::module_name() << " " << CMTK_TESTS_ALPHA_VERSION << std::endl;
    std::cout << alphabet::beta::module_name() << std::endl;
    return EXIT_SUCCESS;
}
