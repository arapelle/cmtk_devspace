#include <iostream>
#include <cpphutil/cpphutil.hpp>
#include <cpphutil/version.hpp>

int main()
{
    std::cout << module_name() << std::endl;
    return EXIT_SUCCESS;
}
