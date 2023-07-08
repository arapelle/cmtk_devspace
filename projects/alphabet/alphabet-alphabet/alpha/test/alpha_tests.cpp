#include <alphabet/alpha/alpha.hpp>
#include <gtest/gtest.h>

TEST(alpha_tests, basic_test)
{
    ASSERT_EQ(alphabet::alpha::module_name(), "alpha");
}
