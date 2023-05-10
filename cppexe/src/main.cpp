#include <cppexe/cppexe.hpp> 
#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << cmtk_tests::cppexe::module_name() << std::endl;
    std::cout << cppexe::module_name() << std::endl;
    return EXIT_SUCCESS;
}
