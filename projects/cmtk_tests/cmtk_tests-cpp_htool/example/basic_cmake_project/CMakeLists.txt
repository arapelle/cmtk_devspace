cmake_minimum_required(VERSION 3.23)

include(CMakePrintHelpers)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package cmtk_tests-cpp_htool:
find_package(cmtk_tests-cpp_htool 0.1.0 CONFIG REQUIRED)
# Use cmtk_tests-cpp_htool release header only target:
target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests-cpp_htool)
