
include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_TARGET_NAME} GTest::gtest_main
                            SOURCES rsc_lib_tests.cpp
)
