#include <cpphutil/cpphutil.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(cpphutil_tests, basic_test)
{
    ASSERT_EQ(cpphutil::module_name(), "cpphutil");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
