
include(cmtk/CMTKNS_CppLibraryTests)
include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

CMTKNS_add_cpp_library_test(cpp_compute_mix_tests ${PROJECT_NAME}-object GTest::gtest_main 
                            SOURCES cpp_compute_mix_tests.cpp
)
target_compile_definitions(cpp_compute_mix_tests PRIVATE UNIT_TEST_VALUE=5)

CMTKNS_add_cpp_library_basic_tests(${PROJECT_NAME}-object GTest::gtest_main
                                   SOURCES cpp_compute_even_tests.cpp
                                           cpp_compute_odd_tests.cpp
)
