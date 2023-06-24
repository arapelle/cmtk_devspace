#include <cmtk_tests/cpp_texe/cpp_texe_main.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

std::string program_path;

TEST(cpp_compute_even_tests, main__2_4_6__14)
{
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::array args = { program_path.c_str(), "2", "4", "6" };
    cpp_texe::main(args.size(), const_cast<char**>(args.data()));

    std::cout.rdbuf(sbuf);
    std::string output_str = buffer.str();
    ASSERT_EQ(output_str.find("[info] operation-0.1.0(2, 4, 6) = 14"), 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    program_path = argv[0];
    return RUN_ALL_TESTS();
}
