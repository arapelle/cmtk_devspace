#include <cpp_hutil/cpp_hutil.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_hutil_tests, basic_test)
{
    ASSERT_EQ(cpp_hutil::module_name(), "cpp_hutil");
}

TEST(cpp_hutil_tests, compute__VALUE_5__5VALUE)
{
#ifndef UNIT_TEST_VALUE
    FAIL();
#else
    ASSERT_EQ(cpp_hutil::compute(UNIT_TEST_VALUE, 5), (5 * UNIT_TEST_VALUE));
#endif
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
