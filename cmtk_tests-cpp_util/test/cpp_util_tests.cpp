#include <cpp_util/cpp_util.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_util_tests, module_name__cpp_util)
{
    ASSERT_EQ(cpp_util::module_name(), "cpp_util");
}

TEST(cpp_util_tests, compute__4_5__20)
{
    ASSERT_EQ(cpp_util::compute(4,5), 20);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
