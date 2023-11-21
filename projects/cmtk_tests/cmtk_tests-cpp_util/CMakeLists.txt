cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "cpp_util")
set_project_semantic_version(0.11.2 PRE_RELEASE "alpha.1" BUILD_METADATA "20231115")
cmake_print_variables(PROJECT_SEMANTIC_VERSION PROJECT_VERSION 
    PROJECT_VERSION_MAJOR PROJECT_VERSION_MINOR PROJECT_VERSION_PATCH
    PROJECT_VERSION_PRE_RELEASE PROJECT_VERSION_BUILD_METADATA
)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

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
add_cpp_library(
  SHARED ${PROJECT_NAME}
  STATIC ${PROJECT_NAME}-static
  BUILD_SHARED OPTION
  BUILD_STATIC OPTION
  HEADERS ${headers} ${configured_headers}
  SOURCES ${sources}
  CXX_STANDARD 20
)

## Link C++ targets:
find_package_if_not_target(spdlog::spdlog spdlog 1.8 REQUIRED CONFIG)
cpp_library_link_libraries(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  PUBLIC
    spdlog::spdlog
    ctre::ctre
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
)
install_uninstall_script(${PROJECT_NAME})

## Add examples:
option(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not" OFF)
if(BUILD_${PROJECT_NAME}_EXAMPLES)
    add_subdirectory(example)
endif()

## Add tests:
option(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
