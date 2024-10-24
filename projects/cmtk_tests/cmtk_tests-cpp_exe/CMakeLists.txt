cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppExecutableProject)
include(cmtk/Spdlog)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "cpp_exe")
set_project_semantic_version(0.1.0 PRE_RELEASE "alpha.1" BUILD_METADATA "20240921")
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_SEMANTIC_VERSION} ${CMAKE_BUILD_TYPE}")

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/cmtk_tests/cpp_exe/cpp_exe.hpp
)

## Sources:
set(sources
    src/cpp_exe.cpp
)

## Add C++ executable:
add_cpp_executable(${PROJECT_NAME}
    HEADERS ${headers} ${configured_headers}
    SOURCES ${sources}
    MAIN src/main.cpp
    CXX_STANDARD 17
    DEFAULT_WARNING_OPTIONS
)

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
set_SPDLOG_ACTIVE_LEVEL_ifndef()

target_SPDLOG_ACTIVE_LEVEL_definition(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)

## Install C++ executable:
install(TARGETS ${PROJECT_NAME})
