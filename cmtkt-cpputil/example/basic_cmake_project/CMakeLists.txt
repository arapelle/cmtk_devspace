cmake_minimum_required(VERSION 3.23)

include(CMakePrintHelpers)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package cmtkt-cpputil:
find_package(cmtkt-cpputil 0.1.0 CONFIG REQUIRED)
# Use cmtkt-cpputil release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE cmtkt-cpputil)
# Use cmtkt-cpputil release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE cmtkt-cpputil-static)
# cmake_print_properties(TARGETS cmtkt-cpputil cmtkt-cpputil-static PROPERTIES INTERFACE_INCLUDE_DIRECTORIES)
