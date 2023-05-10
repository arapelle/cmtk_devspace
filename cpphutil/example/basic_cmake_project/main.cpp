#include <iostream>
#include <cpphutil/cpphutil.hpp>
#include <cpphutil/version.hpp>

int main()
{
    std::cout << cmtk_tests::cpphutil::module_name() << std::endl;
    std::cout << cpphutil::module_name() << std::endl;
    return EXIT_SUCCESS;
}
