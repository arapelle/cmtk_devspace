cmake_minimum_required(VERSION 3.23)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CMTKNS_RscCppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "rsc_lib")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Resource files:
set(resource_files
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/tale.txt                      #    19  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/another-tale.txt              #    29  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/third\ tale.txt               #    27  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc///text///fourth_tale.txt           #    29  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text///short_message/message.txt   #     6  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/icon.png                           #    ~5 Ko
    # ${CMAKE_CURRENT_SOURCE_DIR}/rsc/wallpaper_pink_tree.jpg            #  ~663 Ko
    # ${CMAKE_CURRENT_SOURCE_DIR}/rsc///birds//cardinal.jpg              # ~1.36 Mo
    # ${CMAKE_CURRENT_SOURCE_DIR}/rsc///birds//grey\ bird.jpg            # ~6.05 Mo
)

## Add C++ library:
shared_or_static_option(${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE "SHARED")
if("${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}" STREQUAL "SHARED")
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}")
else()
  set(PROJECT_TARGET_NAME "${PROJECT_NAME}-static")
endif()

CMTKNS_add_rsc_cpp_library(${PROJECT_TARGET_NAME} ${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE} 
    INLINE_CONTEXT_NAMESPACE ${PROJECT_NAMESPACE}
    NAMESPACE ${PROJECT_BASE_NAME}
    HEADERS ${generated_version_header} ${configured_headers}
    RESOURCES ${resource_files}
    RESOURCES_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rsc" 
    VIRTUAL_ROOT "RSC_LIB:/" 
    CXX_STANDARD 20
)

## Add tests:
add_test_subdirectory_if_build(test)

## Add examples:
add_example_subdirectory_if_build(example)

# C++ INSTALL

## Install C++ library:
CMTKNS_install_cpp_libraries(TARGETS ${PROJECT_TARGET_NAME} EXPORT ${PROJECT_NAME}-targets)

## Install project package
CMTKNS_install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})
