#include <iostream>
#include <alphabet/beta/beta.hpp>
#include <alphabet/beta/version.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    std::cout << alphabet::beta::module_name() << " " << ALPHABET_BETA_VERSION << std::endl;
    std::cout << beta::module_name() << " " << ALPHABET_BETA_VERSION << std::endl;
    return EXIT_SUCCESS;
}
