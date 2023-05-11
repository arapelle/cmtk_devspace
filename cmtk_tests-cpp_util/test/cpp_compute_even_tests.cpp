#include <cpp_util/cpp_util.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpp_compute_even_tests, compute__2_4__8)
{
    ASSERT_EQ(cpp_util::compute(2, 4), 8);
}

TEST(cpp_compute_even_tests, compute__6_12__72)
{
    ASSERT_EQ(cpp_util::compute(6, 12), 72);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
