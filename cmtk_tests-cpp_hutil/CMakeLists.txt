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
set(project_feature_name "cpp_hutil")
set(PROJECT_VERSION 0.1.0)
project(${project_namespace}-${project_feature_name} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)
        
## Generated/Configured headers:
generate_version_macro_header(generated_version_header 
                              ${project_namespace}_${project_feature_name}
                              ${project_feature_name}/version.hpp)

## Headers:
set(headers
  include/cpp_hutil/cpp_hutil.hpp
)

## Add C++ library
add_cpp_library(
    PUBLIC
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${generated_version_header} # ${configured_headers}
    CXX_STANDARD 20
)

## Link targets:
find_package(TBB 2021 REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME} INTERFACE TBB::tbb)

## Install C++ library
install_cpp_library(
    HEADER_ONLY ${PROJECT_NAME} 
    EXPORT ${PROJECT_NAME}-targets
)

## Install package
install_library_package(${PROJECT_NAME}
                        INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in
                        UNINSTALL_SCRIPT
)

## Add examples:
option(${PROJECT_NAME}_BUILD_EXAMPLES "Build ${PROJECT_NAME} examples or not" OFF)
if(${PROJECT_NAME}_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

## Add tests:
option(${PROJECT_NAME}_BUILD_TESTS "Build ${PROJECT_NAME} examples or not" OFF)
if(${PROJECT_NAME}_BUILD_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
