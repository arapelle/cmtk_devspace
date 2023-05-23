cmake_minimum_required(VERSION 3.23)

include(CMakePrintHelpers)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package cmtk_tests-alphabet:
find_package(cmtk_tests-alphabet 0.1.0 CONFIG REQUIRED)
# Use cmtk_tests-alphabet release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests-alpha cmtk_tests-beta)
# Use cmtk_tests-alphabet release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE cmtk_tests-alphabet-static cmtk_tests-beta-static)
