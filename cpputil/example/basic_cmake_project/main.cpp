#include <iostream>
#include <cpputil/cpputil.hpp>
#include <cpputil/version.hpp>

int main()
{
    std::cout << module_name() << std::endl;
    return EXIT_SUCCESS;
}
