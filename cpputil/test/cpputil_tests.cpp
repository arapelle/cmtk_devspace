#include <cpputil/cpputil.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpputil_tests, basic_test)
{
    ASSERT_EQ(module_name(), "cpputil");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
