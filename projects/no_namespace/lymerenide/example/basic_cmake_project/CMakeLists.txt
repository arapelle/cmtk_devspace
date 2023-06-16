cmake_minimum_required(VERSION 3.23)

include(CMakePrintHelpers)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package lymerenide:
find_package(lymerenide 0.1.0 CONFIG REQUIRED)
# Use lymerenide release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE lymerenide)
# Use lymerenide release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE lymerenide-static)
