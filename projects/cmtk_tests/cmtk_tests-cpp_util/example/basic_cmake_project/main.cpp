#include <iostream>
#include <cpp_util/cpp_util.hpp>
#include <cpp_util/version.hpp>

int main()
{
    std::cout << cpp_util::module_name() << std::endl;
    std::cout << cmtk_tests::cpp_util::module_name() << std::endl;
    return EXIT_SUCCESS;
}
