#include <iostream>
#include <cmtk_tests/cpp_hutil/cpp_hutil.hpp>
#include <cmtk_tests/cpp_hutil/version.hpp>

int main()
{
    std::cout << cpp_hutil::module_name() << std::endl;
    return EXIT_SUCCESS;
}
