
find_or_fetch_GTest()

add_cpp_library_basic_tests(GTest::gtest_main
                            SHARED assets
                            STATIC assets
                            SOURCES rsc_lib_tests.cpp
)
