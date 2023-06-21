#include <iostream>
#include <cmtk_tests/alphabet/version.hpp>
#include <cmtk_tests/alpha/alpha.hpp>
#include <cmtk_tests/beta/beta.hpp>

int main()
{
    std::cout << CMTK_TESTS_ALPHABET_VERSION << std::endl;
    std::cout << alphabet::alpha::module_name() << std::endl;
    std::cout << alphabet::beta::module_name() << std::endl;
    return EXIT_SUCCESS;
}
