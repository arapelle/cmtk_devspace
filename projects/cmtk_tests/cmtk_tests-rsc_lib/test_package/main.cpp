#include <iostream>
#include <cmtk_tests/rsc_lib/find_serialized_resource.hpp>
#include <cmtk_tests/rsc_lib/version.hpp>
#include <cmtk_tests/rsc_lib/paths.hpp>
#include <cmtk_tests/rsc_lib/icon.hpp>
#include <cmtk_tests/rsc_lib/text/tale.hpp>
#include <cmtk_tests/rsc_lib/text/another_tale.hpp>
#include <cmtk_tests/rsc_lib/text/third_tale.hpp>
#include <cmtk_tests/rsc_lib/text/fourth_tale.hpp>
#include <cmtk_tests/rsc_lib/text/short_message/message.hpp>

int main()
{
    std::cout << CMTK_TESTS_RSC_LIB_VERSION << std::endl;
    std::cout << cmtk_tests::rsc_lib::icon_path << std::endl;
    std::cout << cmtk_tests::rsc_lib::icon().size() << std::endl;
    std::cout << rsc_lib::find_serialized_resource(cmtk_tests::rsc_lib::icon_path)->size() << std::endl;
    return EXIT_SUCCESS;
}
