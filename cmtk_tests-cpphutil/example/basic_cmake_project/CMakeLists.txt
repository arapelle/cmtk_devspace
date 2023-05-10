cmake_minimum_required(VERSION 3.23)

include(CMakePrintHelpers)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package cmtk_tests-cpphutil:
find_package(cmtk_tests-cpphutil 0.1.0 CONFIG REQUIRED)
# Use cmtk_tests-cpphutil release header only target:
target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests-cpphutil)
