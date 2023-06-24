
include(cmtk/CppExecutableTests)

find_or_fetch_GTest()

# add_cpp_executable_test(cpp_util_tests GTest::gtest_main
#                      OBJECT ${PROJECT_NAME}-object
#                      SOURCES cpp_util_tests.cpp
# )
# target_compile_definitions(cpp_util_tests PRIVATE UNIT_TEST_VALUE=5)

add_cpp_executable_basic_tests(GTest::gtest
                            OBJECT ${PROJECT_NAME}-object
                            SOURCES cpp_compute_even_tests.cpp
                              #     cpp_compute_odd_tests.cpp
)
