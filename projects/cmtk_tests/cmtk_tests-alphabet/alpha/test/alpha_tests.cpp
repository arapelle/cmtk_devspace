#include <cmtk_tests/alpha/alpha.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(alpha_tests, basic_test)
{
    ASSERT_EQ(alphabet::alpha::module_name(), "alpha");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
