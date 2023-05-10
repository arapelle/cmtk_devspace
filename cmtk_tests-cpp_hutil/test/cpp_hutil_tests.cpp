#include <cpp_hutil/cpp_hutil.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_hutil_tests, basic_test)
{
    ASSERT_EQ(cpp_hutil::module_name(), "cpp_hutil");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
