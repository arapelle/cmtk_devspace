
find_or_fetch_GTest()

add_cpp_library_basic_tests(GTest::gtest_main
                            HEADER_ONLY ${PROJECT_NAME}
                            SOURCES cpphutil_tests.cpp
)
