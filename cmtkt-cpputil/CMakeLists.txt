cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

check_cmake_binary_dir()
set_build_type_ifndef()

# C++ PROJECT

set(project_namespace "cmtk_tests")
set(project_feature_name "cpputil")
set(PROJECT_VERSION 0.1.0)
project(${project_namespace}-${project_feature_name} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
generate_macro_version_header(generated_version_header 
                              ${project_namespace}_${project_feature_name}
                              ${project_feature_name}/version.hpp)

## Headers:
set(headers
include/cpputil/cpputil.hpp
)

## Sources:
set(sources
src/cpputil.cpp
)

## Add C++ library:
add_cpp_library(
  PUBLIC
  SHARED ${PROJECT_NAME}
  STATIC ${PROJECT_NAME}-static
  HEADERS ${headers} ${generated_version_header} # ${configured_headers}
  SOURCES ${sources}
  CXX_STANDARD 20
)

## Link C++ targets:
find_package(TBB 2021 REQUIRED CONFIG)
cpp_library_link_libraries(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  PUBLIC TBB::tbb
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

## Add examples:
option(BUILD_${PROJECT_NAME}_EXAMPLES "Build appt examples or not" OFF)
if(BUILD_${PROJECT_NAME}_EXAMPLES)
    add_subdirectory(example)
endif()

## Add tests:
option(BUILD_${PROJECT_NAME}_TESTS "Build appt examples or not" OFF)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
