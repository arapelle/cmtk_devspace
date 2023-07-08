cmake_minimum_required(VERSION 3.23)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package alphabet-alphabet:
find_package(alphabet-alphabet 0.1.0 CONFIG REQUIRED)
# Use alphabet-alphabet release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE alphabet-alphabet)
# Use alphabet-alphabet release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE alphabet-alphabet-static)
