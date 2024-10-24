include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_cpp_library_test(cpp_util_tests ${PROJECT_TARGET_NAME} GTest::gtest_main 
                     SOURCES cpp_util_tests.cpp
)
target_compile_definitions(cpp_util_tests PRIVATE UNIT_TEST_VALUE=5)

add_cpp_library_basic_tests(${PROJECT_TARGET_NAME} GTest::gtest_main
                            SOURCES cpp_compute_even_tests.cpp
                                    cpp_compute_odd_tests.cpp
)
