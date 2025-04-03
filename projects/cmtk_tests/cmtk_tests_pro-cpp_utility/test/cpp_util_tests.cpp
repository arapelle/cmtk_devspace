#include <cmtk_tests/cpp_util/cpp_util.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_util_tests, module_name__cpp_util)
{
    ASSERT_EQ(cpp_util::module_name(), "cmtk_tests-cpp_util");
}

TEST(cpp_util_tests, compute__VALUE_5__5VALUE)
{
#ifndef UNIT_TEST_VALUE
    FAIL();
#else
    ASSERT_EQ(cpp_util::compute(UNIT_TEST_VALUE, 5), (5 * UNIT_TEST_VALUE));
#endif
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
