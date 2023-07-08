cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# C++ PROJECT

set(PROJECT_NAME "alphabet-alpha")
set(project_namespace "alphabet")
set(project_base_name "alpha")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)

message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

# C++ LIBRARY

## Generated/Configured headers:
generate_version_macro_header(generated_version_header 
                              ${project_namespace}_${project_base_name}
                              ${project_namespace}/${project_base_name}/version.hpp)

## Headers:
set(headers
    include/alphabet/alpha/alpha.hpp
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
    HEADERS ${headers} ${generated_version_header}
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
