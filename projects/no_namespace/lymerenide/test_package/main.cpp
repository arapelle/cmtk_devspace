#include <iostream>
#include <lymerenide/lymerenide.hpp>
#include <lymerenide/version.hpp>

int main()
{
    std::cout << lymerenide::module_name() << std::endl;
    return EXIT_SUCCESS;
}
