#include <alphabet/beta/version.hpp>
#include <gtest/gtest.h>

TEST(beta_project_version_tests, test_version_macros)
{
    ASSERT_EQ(ALPHABET_BETA_VERSION_MAJOR, 0);
    ASSERT_EQ(ALPHABET_BETA_VERSION_MINOR, 1);
    ASSERT_EQ(ALPHABET_BETA_VERSION_PATCH, 0);
    ASSERT_STREQ(ALPHABET_BETA_VERSION, "0.1.0");
}
