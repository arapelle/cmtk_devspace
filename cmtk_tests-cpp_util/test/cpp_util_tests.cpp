#include <cpp_util/cpp_util.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_util_tests, basic_test)
{
    ASSERT_EQ(cpp_util::module_name(), "cpp_util");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
