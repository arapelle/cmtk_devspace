#include <alphabet/alpha/version.hpp>
#include <gtest/gtest.h>

TEST(project_version_tests, test_version_macros)
{
    ASSERT_EQ(ALPHABET_ALPHA_VERSION_MAJOR, 0);
    ASSERT_EQ(ALPHABET_ALPHA_VERSION_MINOR, 1);
    ASSERT_EQ(ALPHABET_ALPHA_VERSION_PATCH, 0);
    ASSERT_STREQ(ALPHABET_ALPHA_VERSION, "0.1.0");
}
