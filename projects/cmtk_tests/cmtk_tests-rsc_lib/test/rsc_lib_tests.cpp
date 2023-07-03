#include <assets/assets.hpp>
#include <gtest/gtest.h>

TEST(rsc_lib_tests, resource__size__ok)
{
    EXPECT_EQ(assets::grey_bird_path, "ASSETS:/birds/grey bird.jpg");
    EXPECT_EQ(assets::grey_bird.size(), 6353336);
}

TEST(rsc_lib_tests, find_serialized_resource__tale__found)
{
    std::string_view rsc_path = "ASSETS:/text/tale.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_TRUE(static_cast<bool>(rsc_bytes_o));
    EXPECT_EQ(rsc_bytes_o->size(), 19);
    std::span rsc_bytes(*rsc_bytes_o);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes.data()), rsc_bytes.size());
    EXPECT_EQ(content, "Once upon a time...");
}

// resource_map()

TEST(rsc_lib_tests, find_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "ASSETS:/trap.txt";
    std::optional rsc_bytes_o = assets::find_serialized_resource(rsc_path);
    EXPECT_FALSE(static_cast<bool>(rsc_bytes_o));
}
