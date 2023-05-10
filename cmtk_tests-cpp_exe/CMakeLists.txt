cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../)
include(CMakePrintHelpers)
include(cmtk/CppExecutableProject)

# CONFIGURATION

check_cmake_binary_dir()
set_build_type_ifndef()

# C++ PROJECT

set(project_namespace "cmtk_tests")
set(project_feature_name "cppexe")
set(PROJECT_VERSION 0.1.0)
project(${project_namespace}-${project_feature_name} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

## Headers:
set(headers
    include/cppexe/cppexe.hpp
)

## Sources:
set(sources
    src/cppexe.cpp
    src/main.cpp
)

## Add C++ executable:
add_cpp_executable(${PROJECT_NAME}
    CXX_STANDARD 17
    INCLUDE_DIRECTORIES include
    VERSION_HEADER "version.hpp"
    HEADERS ${headers}
    SOURCES ${sources}
    )

## Install C++ executable:
install(TARGETS ${PROJECT_NAME})
