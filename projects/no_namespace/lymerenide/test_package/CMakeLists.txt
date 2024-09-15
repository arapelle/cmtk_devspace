cmake_minimum_required(VERSION 3.23)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)

find_package(lymerenide 0.1.0 CONFIG REQUIRED)
if(TARGET lymerenide)
    target_link_libraries(${PROJECT_NAME} PRIVATE lymerenide)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE lymerenide-static)
endif()
