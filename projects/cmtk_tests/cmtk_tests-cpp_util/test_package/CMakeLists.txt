cmake_minimum_required(VERSION 3.23)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)

find_package(cmtk_tests_pro-cpp_utility 0.1.0 CONFIG REQUIRED)
if(TARGET cmtk_tests_pro-cpp_utility)
    target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests_pro-cpp_utility)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests_pro-cpp_utility-static)
endif()
