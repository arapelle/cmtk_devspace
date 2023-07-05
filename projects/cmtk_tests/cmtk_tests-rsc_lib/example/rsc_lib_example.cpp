#include <iostream>
#include <cmtk_tests/rsc_lib/rsc_lib.hpp>
#include <cmtk_tests/rsc_lib/paths.hpp>
#include <cmtk_tests/rsc_lib/icon.hpp>

int main()
{
    std::cout << cmtk_tests::rsc_lib::icon_path << std::endl;
    std::cout << cmtk_tests::rsc_lib::icon().size() << std::endl;
    std::cout << rsc_lib::find_serialized_resource(cmtk_tests::rsc_lib::icon_path)->size() << std::endl;
    return EXIT_SUCCESS;
}
