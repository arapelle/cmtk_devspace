cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(cmtk/CppProject)
include(CMakePrintHelpers)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ MULTI-PROJECT

set(PROJECT_NAME "alphabet-alphabet")
set(project_namespace "alphabet")
set(project_feature_name "alphabet")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

## C++ gathering target

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}-static INTERFACE)

trioption(BUILD_${PROJECT_NAME} "Indicates if we build a SHARED library." ON)
trioption(BUILD_${PROJECT_NAME}-static "Indicates if we build a STATIC library." ON)
trioption(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not." OFF)
trioption(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not." OFF)

## Generated/Configured headers:
generate_version_macro_header(generated_version_header 
                              ${project_namespace}
                              ${project_namespace}/version.hpp)

target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS BASE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}/include FILES ${generated_version_header})

### Add sub-projects and link with them:
set(libraries
    alpha
    beta
)

foreach(library ${libraries})
    add_subdirectory(${library})
    if(TARGET ${project_namespace}-${library})
        target_link_libraries(${PROJECT_NAME} INTERFACE ${project_namespace}-${library})
    endif()
    if(TARGET ${project_namespace}-${library}-static)
        target_link_libraries(${PROJECT_NAME}-static INTERFACE ${project_namespace}-${library}-static)
    endif()
endforeach()

### Export targets
install_cpp_library(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  EXPORT ${PROJECT_NAME}-targets
)

# Install package
install_library_package(${PROJECT_NAME}
    INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in
)
install_uninstall_script(${PROJECT_NAME} ALL)
