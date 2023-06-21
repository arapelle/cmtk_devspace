#include <cmtk_tests/cpp_texe/cpp_texe_main.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_compute_even_tests, main__2_4_6__8)
{
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::array args = { "2", "4", "6" };
    cpp_texe::main(args.size(), const_cast<char**>(args.data()));

    std::cout.rdbuf(sbuf);
    std::string output_str = buffer.str();
    ASSERT_EQ(output_str.find("[info] operation-0.1.0(4, 6, 0) = 24"), 0);
}

// TEST(cpp_compute_even_tests, compute__6_12__72)
// {
//     ASSERT_EQ(cpp_util::compute(6, 12), 72);
// }
