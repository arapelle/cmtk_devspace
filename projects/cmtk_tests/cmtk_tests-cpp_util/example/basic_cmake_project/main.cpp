#include <iostream>
#include <cmtk_tests/cpp_util/cpp_util.hpp>
#include <cmtk_tests/cpp_util/version.hpp>

int main()
{
    std::cout << cpp_util::module_name() << std::endl;
    std::cout << cmtk_tests::cpp_util::module_name() << std::endl;
    return EXIT_SUCCESS;
}
