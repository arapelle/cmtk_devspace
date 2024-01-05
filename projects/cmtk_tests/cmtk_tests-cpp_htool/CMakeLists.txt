cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "cpp_htool")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
  include/${PROJECT_NAMESPACE}/cpp_htool/cpp_htool.hpp
)

## Add C++ library
add_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${configured_headers}
    CXX_STANDARD 20
)

## Install C++ library
install_cpp_library(
    HEADER_ONLY ${PROJECT_NAME} 
    EXPORT ${PROJECT_NAME}-targets
)

## Install package
install_library_package(${PROJECT_NAME}
                        INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in
)
install_uninstall_script(${PROJECT_NAME})

## Add examples:
option(${PROJECT_NAME}_BUILD_EXAMPLES "Build ${PROJECT_NAME} examples or not" OFF)
if(${PROJECT_NAME}_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

## Add tests:
option(${PROJECT_NAME}_BUILD_TESTS "Build ${PROJECT_NAME} tests or not" OFF)
if(${PROJECT_NAME}_BUILD_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
