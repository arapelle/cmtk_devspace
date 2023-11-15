cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/RscCppLibraryProject)

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
generate_version_macro_header(generated_version_header 
                              ${PROJECT_NAMESPACE}_${PROJECT_BASE_NAME}
                              ${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp)

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
add_rsc_cpp_library(
    INLINE_PARENT_NAMESPACE ${PROJECT_NAMESPACE}
    NAME ${PROJECT_BASE_NAME}
    SHARED ${PROJECT_NAME}
    STATIC ${PROJECT_NAME}-static
    BUILD_SHARED OPTION
    BUILD_STATIC OPTION
    HEADERS ${generated_version_header}
    RESOURCES ${resource_files}
    RESOURCES_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rsc" 
    VIRTUAL_ROOT "RSC_LIB:/" 
    CXX_STANDARD 20
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
