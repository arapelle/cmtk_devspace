
find_or_fetch_GTest()

add_cpp_library_test(lymerenide_tests GTest::gtest_main
                     SHARED ${PROJECT_NAME}
                     STATIC ${PROJECT_NAME}-static
                     SOURCES lymerenide_tests.cpp
)
target_compile_definitions(lymerenide_tests PRIVATE UNIT_TEST_VALUE=5)

add_cpp_library_basic_tests(GTest::gtest_main
                            SHARED ${PROJECT_NAME}
                            STATIC ${PROJECT_NAME}-static
                            SOURCES compute_even_tests.cpp
                                    compute_odd_tests.cpp
)
