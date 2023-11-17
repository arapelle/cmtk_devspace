cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/RscCppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAME "resorice")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAME}/version.hpp.in
)

## Resource files:
set(resource_files
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text///tale.txt                    #    19  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/another-tale.txt              #    29  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/message.txt                        #     6  o
)

## Add C++ library:
add_rsc_cpp_library(
    NAME ${PROJECT_NAME}
    SHARED ${PROJECT_NAME}
    STATIC ${PROJECT_NAME}-static
    BUILD_SHARED OPTION
    BUILD_STATIC OPTION
    HEADERS ${generated_version_header} ${configured_headers}
    RESOURCES ${resource_files}
    RESOURCES_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rsc" 
    VIRTUAL_ROOT "RESORICE:/"
    CXX_STANDARD 20
    PRIVATE_RESOURCE_HEADERS
    PRIVATE_RESOURCE_PATHS_HEADER
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
