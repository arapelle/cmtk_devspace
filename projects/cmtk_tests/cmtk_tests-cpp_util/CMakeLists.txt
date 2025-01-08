cmake_minimum_required(VERSION 3.23)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)
include(cmtk/Spdlog)

# CONFIGURATION

check_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "cpp_util")
set_project_semantic_version(0.11.2 PRE_RELEASE "alpha.1" BUILD_METADATA "20231115")
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
        message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_SEMANTIC_VERSION} ${CMAKE_BUILD_TYPE}")

# C++ LIBRARY

## Include external dependencies:

add_subdirectory(external)

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
  include/${PROJECT_NAMESPACE}/cpp_util/cpp_util.hpp
)

## Sources:
set(sources
  src/cpp_util.cpp
)

## Add C++ library:
shared_or_static_option(${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE "SHARED")
if("${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}" STREQUAL "SHARED")
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}")
else()
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}-static")
endif()

add_cpp_library(${PROJECT_TARGET_NAME} ${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}
  HEADERS ${headers} ${configured_headers}
  SOURCES ${sources}
  CXX_STANDARD 20
  DEFAULT_WARNING_OPTIONS
)

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
set_SPDLOG_ACTIVE_LEVEL_ifndef()

target_SPDLOG_ACTIVE_LEVEL_definition(${PROJECT_TARGET_NAME})
target_link_libraries(${PROJECT_TARGET_NAME} 
  PUBLIC
    spdlog::spdlog
    ctre::ctre
)

## Add tests:
add_test_subdirectory_if_build(test)

## Add examples:
add_example_subdirectory_if_build(example)

# C++ INSTALL

## Install C++ library:
install_cpp_libraries(TARGETS ${PROJECT_TARGET_NAME} EXPORT ${PROJECT_NAME}-targets)

## Install project package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})
