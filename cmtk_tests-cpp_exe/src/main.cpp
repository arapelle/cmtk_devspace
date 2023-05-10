#include <cpp_exe/cpp_exe.hpp> 
#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << cmtk_tests::cpp_exe::module_name() << std::endl;
    std::cout << cpp_exe::module_name() << std::endl;
    return EXIT_SUCCESS;
}
