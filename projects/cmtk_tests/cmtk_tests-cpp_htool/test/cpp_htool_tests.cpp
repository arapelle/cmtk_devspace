#include <cmtk_tests/cpp_htool/cpp_htool.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_htool_tests, basic_test)
{
    ASSERT_EQ(cpp_htool::module_name(), "cpp_htool");
}

TEST(cpp_htool_tests, compute__VALUE_5__5VALUE)
{
#ifndef UNIT_TEST_VALUE
    FAIL();
#else
    ASSERT_EQ(cpp_htool::compute(UNIT_TEST_VALUE, 5), (5 * UNIT_TEST_VALUE));
#endif
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
