#include <cmtk_tests/cpp_texe/cpp_texe_main.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

std::string program_path;

TEST(cpp_compute_even_tests, main__3_5_7__22)
{
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::array args = { program_path.c_str(), "3", "5", "7" };
    cpp_texe::main(args.size(), const_cast<char**>(args.data()));

    std::cout.rdbuf(sbuf);
    std::string output_str = buffer.str();
    ASSERT_EQ(output_str.find("[info] operation-0.1.0(3, 5, 7) = 22"), 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    program_path = argv[0];
    return RUN_ALL_TESTS();
}
