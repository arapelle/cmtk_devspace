
find_or_fetch_GTest()

add_cpp_library_test(cpp_hutil_tests GTest::gtest_main
                     HEADER_ONLY ${PROJECT_NAME}
                     SOURCES cpp_hutil_tests.cpp
)
target_compile_definitions(cpp_hutil_tests PRIVATE UNIT_TEST_VALUE=5)

add_cpp_library_basic_tests(GTest::gtest_main
                            HEADER_ONLY ${PROJECT_NAME}
                            SOURCES cpp_compute_even_tests.cpp
                                    cpp_compute_odd_tests.cpp
)
