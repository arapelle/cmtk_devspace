#include <iostream>
#include <cpp_hutil/cpp_hutil.hpp>
#include <cpp_hutil/version.hpp>

int main()
{
    std::cout << cmtk_tests::cpp_hutil::module_name() << std::endl;
    std::cout << cpp_hutil::module_name() << std::endl;
    return EXIT_SUCCESS;
}
