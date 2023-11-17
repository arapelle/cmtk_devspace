cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# C++ PROJECT

set(PROJECT_NAME "alphabet-beta")
set(PROJECT_NAMESPACE "alphabet")
set(PROJECT_BASE_NAME "beta")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)

message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/alphabet/beta/beta.hpp
)

## Add C++ library:
add_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${configured_headers}
    CXX_STANDARD 20
)

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME}
    INTERFACE
        spdlog::spdlog
)

## Install C++ library:
install_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
)

## Install project package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})

## Add tests:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF BUILD_${CMAKE_PROJECT_NAME}_TESTS)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()

## Add examples:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not" OFF BUILD_${CMAKE_PROJECT_NAME}_EXAMPLES)
if(BUILD_${PROJECT_NAME}_EXAMPLES AND BUILD_TESTING)
    add_subdirectory(example)
endif()
