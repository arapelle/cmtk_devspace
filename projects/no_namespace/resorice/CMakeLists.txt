cmake_minimum_required(VERSION 3.23)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/RscCppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAME "resorice")
set(PROJECT_VERSION 0.1.0)
set(PACKAGE_NAME ${PROJECT_NAME})
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
shared_or_static_option(${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE "SHARED")
if("${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}" STREQUAL "SHARED")
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}")
else()
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}-static")
endif()

add_rsc_cpp_library(${PROJECT_TARGET_NAME} ${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE} 
    NAMESPACE ${PROJECT_NAME}
    HEADERS ${generated_version_header} ${configured_headers}
    RESOURCES ${resource_files}
    RESOURCES_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rsc" 
    VIRTUAL_ROOT "RESORICE:/" 
    CXX_STANDARD 20
    PRIVATE_RESOURCE_HEADERS
    PRIVATE_RESOURCE_PATHS_HEADER
)

## Add tests:
add_test_subdirectory_if_built(test)

## Add examples:
add_example_subdirectory_if_built(example)

# C++ INSTALL

## Install C++ library:
install_cpp_targets(TARGETS ${PROJECT_TARGET_NAME} EXPORT ${PROJECT_NAME}-targets)

## Install project package
install_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})
