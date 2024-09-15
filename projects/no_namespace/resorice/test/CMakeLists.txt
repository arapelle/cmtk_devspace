
include(cmtk/CMTKNS_CppLibraryTests)
include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

CMTKNS_add_cpp_library_basic_tests(${PROJECT_TARGET_NAME} GTest::gtest_main
                            SOURCES resorice_tests.cpp
)
