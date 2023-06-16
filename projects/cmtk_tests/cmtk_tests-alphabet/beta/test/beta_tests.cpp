#include <beta/beta.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(beta_tests, basic_test)
{
    ASSERT_EQ(alphabet::beta::module_name(), "beta");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
