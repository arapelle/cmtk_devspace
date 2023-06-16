#include <iostream>
#include <alpha/alpha.hpp>
#include <beta/beta.hpp>

int main()
{
    std::cout << alphabet::alpha::module_name() << std::endl;
    std::cout << alphabet::beta::module_name() << std::endl;
    return EXIT_SUCCESS;
}
