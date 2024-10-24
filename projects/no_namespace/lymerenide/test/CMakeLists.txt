
include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_cpp_library_test(lymerenide_tests ${PROJECT_TARGET_NAME} GTest::gtest_main 
                     SOURCES lymerenide_tests.cpp
)
target_compile_definitions(lymerenide_tests PRIVATE UNIT_TEST_VALUE=5)

add_cpp_library_basic_tests(${PROJECT_TARGET_NAME} GTest::gtest_main
                            SOURCES
                                compute_even_tests.cpp
                                compute_odd_tests.cpp
)
