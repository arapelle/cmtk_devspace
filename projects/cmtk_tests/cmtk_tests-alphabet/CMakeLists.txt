cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(cmtk/Project)
include(CMakePrintHelpers)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ MULTI-PROJECT

set(PROJECT_NAME "cmtk_tests-alphabet")
set(project_namespace "cmtk_tests")
set(project_feature_name "alphabet")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

trioption(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF)

# C++ PROJECT: alpha

add_subdirectory(alpha)
