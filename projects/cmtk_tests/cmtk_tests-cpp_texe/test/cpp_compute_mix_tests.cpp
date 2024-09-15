#include <cmtk_tests/cpp_texe/cpp_texe_main.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

std::string program_path;

TEST(cpp_compute_mix_test, main__2_4_5__13)
{
#ifndef UNIT_TEST_VALUE
    FAIL();
#else
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::string unit_test_value = std::to_string(UNIT_TEST_VALUE);
    std::array args = { program_path.c_str(), "2", "4", unit_test_value.c_str() };
    cpp_texe::main(args.size(), const_cast<char**>(args.data()));

    std::cout.rdbuf(sbuf);
    std::string output_str = buffer.str();
    ASSERT_EQ(output_str.find("[info] operation-0.11.2(2, 4, 5) = 13"), 0);
#endif
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    program_path = argv[0];
    return RUN_ALL_TESTS();
}
