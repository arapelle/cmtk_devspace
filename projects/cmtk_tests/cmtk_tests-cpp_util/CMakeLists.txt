cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set(PROJECT_NAME "cmtk_tests-cpp_util")
set(project_namespace "cmtk_tests")
set(project_feature_name "cpp_util")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
generate_version_macro_header(generated_version_header 
                              ${project_namespace}_${project_feature_name}
                              ${project_namespace}/${project_feature_name}/version.hpp)

## Headers:
set(headers
include/${project_namespace}/cpp_util/cpp_util.hpp
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
  HEADERS ${headers} ${generated_version_header} # ${configured_headers}
  SOURCES ${sources}
  CXX_STANDARD 20
)

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
cpp_library_link_libraries(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  PUBLIC spdlog::spdlog
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
