#include <lymerenide/lymerenide.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(compute_odd_tests, compute__7_11__77)
{
    ASSERT_EQ(lymerenide::compute(7, 11), 77);
}

TEST(compute_odd_tests, compute__3_5__15)
{
    ASSERT_EQ(lymerenide::compute(3, 5), 15);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
