#include <iostream>
#include <lymerenide/lymerenide.hpp>
#include <lymerenide/version.hpp>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    std::cout << lymerenide::module_name() << "-" << LYMERENIDE_VERSION << std::endl;
    std::cout << lymerenide::compute(6, 7) << std::endl;
    return EXIT_SUCCESS;
}
