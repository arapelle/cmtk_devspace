#include <iostream>
#include <alphabet/alpha/alpha.hpp>
#include <alphabet/alpha/version.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    std::cout << alphabet::alpha::module_name() << " " << ALPHABET_ALPHA_VERSION << std::endl;
    std::cout << alpha::module_name() << " " << ALPHABET_ALPHA_VERSION << std::endl;
    return EXIT_SUCCESS;
}
