cmake_minimum_required(VERSION 3.25)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)
include(cmtk/Spdlog)

# CONFIGURATION

check_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests_pro" FEATURE_NAME "cpp_utility" CODE_NAMESPACE "cmtk_tests" CODE_FEATURE_NAME "cpp_util")
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
        include/${PROJECT_CODE_NAMESPACE}/${PROJECT_CODE_FEATURE_NAME}/version.hpp.in
        include/${PROJECT_CODE_NAMESPACE}/${PROJECT_CODE_FEATURE_NAME}/cpp_util.hpp.in
)

## Generated/Configured sources:
configure_headers(configured_sources
    FILES
        src/cpp_util.cpp.in
)

## Add C++ library:
shared_or_static_option(${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE "SHARED")
if("${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}" STREQUAL "SHARED")
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}")
else()
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}-static")
endif()

cxx_standard_option(${PROJECT_UPPER_VAR_NAME}_CXX_STANDARD MIN 98 MAX 23)

add_cpp_library(${PROJECT_TARGET_NAME} ${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}
  HEADERS ${headers} ${configured_headers}
  SOURCES ${configured_sources}
  CXX_STANDARD ${${PROJECT_UPPER_VAR_NAME}_CXX_STANDARD}
  DEFAULT_WARNING_OPTIONS
  DEFAULT_ERROR_OPTIONS
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
