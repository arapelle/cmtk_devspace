#include <iostream>
#include <cmtk_tests/cpp_htool/cpp_htool.hpp>
#include <cmtk_tests/cpp_htool/version.hpp>

int main()
{
    std::cout << cpp_htool::module_name() << std::endl;
    return EXIT_SUCCESS;
}
