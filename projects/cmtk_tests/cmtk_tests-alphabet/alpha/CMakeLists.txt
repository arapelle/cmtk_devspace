cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# C++ PROJECT

set(PROJECT_NAME "cmtk_tests-alpha")
set(project_namespace "cmtk_tests")
set(project_feature_name "alpha")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)

message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

# C++ LIBRARY

## Headers:
set(headers
include/cmtk_tests/alpha/alpha.hpp
)

## Sources:
set(sources
src/alpha.cpp
)

## Add C++ library:
add_cpp_library(
  SHARED ${PROJECT_NAME}
  STATIC ${PROJECT_NAME}-static
  BUILD_SHARED ${BUILD_${CMAKE_PROJECT_NAME}}
  BUILD_STATIC ${BUILD_${CMAKE_PROJECT_NAME}-static}
  HEADERS ${headers}
  SOURCES ${sources}
  CXX_STANDARD 20
)

## Install C++ library:
install_cpp_library(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  EXPORT ${PROJECT_NAME}-targets
)

## Install project package
install_library_package(${PROJECT_NAME}
                        INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in
                        UNINSTALL_SCRIPT
)

## Add tests:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF BUILD_${CMAKE_PROJECT_NAME}_TESTS)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
