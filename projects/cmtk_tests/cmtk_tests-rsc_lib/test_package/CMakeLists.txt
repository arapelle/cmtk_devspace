cmake_minimum_required(VERSION 3.23)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)

find_package(cmtk_tests-rsc_lib 0.1.0 CONFIG REQUIRED)
if(TARGET cmtk_tests-rsc_lib)
    target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests-rsc_lib)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE cmtk_tests-rsc_lib-static)
endif()
