#include <lymerenide/lymerenide.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(lymerenide_tests, module_name__lymerenide)
{
    ASSERT_EQ(lymerenide::module_name(), "lymerenide");
}

TEST(lymerenide_tests, compute__VALUE_5__5VALUE)
{
#ifndef UNIT_TEST_VALUE
    FAIL();
#else
    ASSERT_EQ(lymerenide::compute(UNIT_TEST_VALUE, 5), (5 * UNIT_TEST_VALUE));
#endif
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
