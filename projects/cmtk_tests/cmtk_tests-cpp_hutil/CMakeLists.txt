cmake_minimum_required(VERSION 3.23)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)
include(cmtk/Spdlog)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "cpp_hutil")
set_project_semantic_version(0.11.2 PRE_RELEASE "alpha.1" BUILD_METADATA "20231115")
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_SEMANTIC_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
  include/${PROJECT_NAMESPACE}/cpp_hutil/cpp_hutil.hpp
)

## Add C++ library
add_cpp_library(${PROJECT_NAME} HEADER_ONLY
  HEADERS ${headers} ${configured_headers}
  CXX_STANDARD 20
  DEFAULT_WARNING_OPTIONS
)

## Link targets:
find_package(TBB 2021 REQUIRED CONFIG)

target_link_libraries(${PROJECT_NAME} INTERFACE TBB::tbb)

## Add tests:
add_test_subdirectory_if_build(test)

## Add examples:
add_example_subdirectory_if_build(example)

# C++ INSTALL

## Install C++ library:
install_cpp_libraries(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets)

## Install project package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})
