cmake_minimum_required(VERSION 3.23)

include(CMakePrintHelpers)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package resorice:
find_package(resorice 0.1.0 CONFIG REQUIRED)
# Use resorice release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE resorice)
# Use resorice release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE resorice-static)
