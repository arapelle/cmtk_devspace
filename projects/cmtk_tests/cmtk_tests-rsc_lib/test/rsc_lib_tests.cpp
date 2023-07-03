#include <assets/assets.hpp>
#include <assets/icon.hpp>
#include <assets/text/tale.hpp>
#include <assets/text/another_tale.hpp>
#include <assets/text/third_tale.hpp>
#include <assets/text/fourth_tale.hpp>
#include <assets/text/short_message/message.hpp>
#include <gtest/gtest.h>

TEST(rsc_lib_tests, resource_icon__path_and_size__ok)
{
    EXPECT_EQ(assets::icon_path, "ASSETS:/icon.png");
    EXPECT_EQ(assets::icon().size(), 5465);
}

TEST(rsc_lib_tests, resource_tale__path_and_size__ok)
{
    EXPECT_EQ(assets::text::tale_path, "ASSETS:/text/tale.txt");
    EXPECT_EQ(assets::text::tale().size(), 19);
}

TEST(rsc_lib_tests, resource_message__path_and_size__ok)
{
    EXPECT_EQ(assets::text::short_message::message_path, "ASSETS:/text/short_message/message.txt");
    EXPECT_EQ(assets::text::short_message::message().size(), 6);
}

TEST(rsc_lib_tests, find_serialized_resource__tale__found)
{
    std::string_view rsc_path = "ASSETS:/text/tale.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->data(), assets::text::tale().data());
    EXPECT_EQ(rsc_bytes_o->size(), assets::text::tale().size());
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "Once upon a time...");
}

TEST(rsc_lib_tests, find_serialized_resource__another_tale__found)
{
    std::string_view rsc_path = "ASSETS:/text/another-tale.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->data(), assets::text::another_tale().data());
    EXPECT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "Once upon a time, a knight...");
}

TEST(rsc_lib_tests, find_serialized_resource__third_tale__found)
{
    std::string_view rsc_path = "ASSETS:/text/third tale.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->data(), assets::text::third_tale().data());
    EXPECT_EQ(rsc_bytes_o->size(), 27);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "Once upon a time, a frog...");
}

TEST(rsc_lib_tests, find_serialized_resource__fourth_tale__found)
{
    std::string_view rsc_path = "ASSETS:/text/fourth_tale.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->data(), assets::text::fourth_tale().data());
    EXPECT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "Once upon a time, a dragon...");
}

TEST(rsc_lib_tests, find_serialized_resource__message__found)
{
    std::string_view rsc_path = "ASSETS:/text/short_message/message.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->data(), assets::text::short_message::message().data());
    EXPECT_EQ(rsc_bytes_o->size(), 6);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    EXPECT_EQ(content, "coucou");
}

TEST(rsc_lib_tests, find_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "ASSETS:/trap.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_FALSE(static_cast<bool>(rsc_bytes_o));
}
