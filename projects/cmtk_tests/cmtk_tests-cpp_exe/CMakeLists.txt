cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppExecutableProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set(project_namespace "cmtk_tests")
set(project_feature_name "cpp_exe")
set(PROJECT_VERSION 0.1.0)
project(${project_namespace}-${project_feature_name} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

## Headers:
set(headers
    include/cpp_exe/cpp_exe.hpp
)

## Sources:
set(sources
    src/cpp_exe.cpp
    src/main.cpp
)

## Add C++ executable:
add_cpp_executable(${PROJECT_NAME}
    CXX_STANDARD 17
    INCLUDE_DIRECTORIES include
    VERSION_HEADER "version.hpp"
    HEADERS ${headers}
    SOURCES ${sources}
    )

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
set_spdlog_active_level_ifndef()
target_compile_definitions(${PROJECT_NAME} PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_${SPDLOG_ACTIVE_LEVEL})
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)

## Install C++ executable:
install(TARGETS ${PROJECT_NAME})
