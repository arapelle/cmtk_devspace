#include <resorice/resorice.hpp>
#include <resorice/version.hpp>
#include <gtest/gtest.h>

TEST(resorice_tests, version__check__ok)
{
    EXPECT_EQ(RESORICE_VERSION, "0.1.0");
}

TEST(resorice_tests, find_serialized_resource__tale__found)
{
    std::string_view rsc_path = "RESORICE:/text/tale.txt";
    std::optional rsc_bytes_o = resorice::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->size(), 19);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "Once upon a time...");
}

TEST(resorice_tests, find_serialized_resource__another_tale__found)
{
    std::string_view rsc_path = "RESORICE:/text/another-tale.txt";
    std::optional rsc_bytes_o = resorice::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "Once upon a time, a knight...");
}

TEST(resorice_tests, find_serialized_resource__message__found)
{
    std::string_view rsc_path = "RESORICE:/message.txt";
    std::optional rsc_bytes_o = resorice::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->size(), 6);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "coucou");
}

TEST(resorice_tests, find_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "RESORICE:/trap.txt";
    std::optional rsc_bytes_o = resorice::find_serialized_resource(rsc_path);
    EXPECT_FALSE(static_cast<bool>(rsc_bytes_o));
}
