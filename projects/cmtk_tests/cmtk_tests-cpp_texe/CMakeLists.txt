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

set_project_name(NAMESPACE "cmtk_tests" BASE_NAME "cpp_texe")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/${PROJECT_NAMESPACE}/cpp_texe/cpp_texe.hpp
    include/${PROJECT_NAMESPACE}/cpp_texe/cpp_texe_main.hpp
)

## Sources:
set(sources
    src/cpp_texe.cpp
    src/cpp_texe_main.cpp
)

## Add C++ executable:
add_cpp_executable(${PROJECT_NAME}
    OBJECT ${PROJECT_NAME}-object
    CXX_STANDARD 17
    HEADERS ${headers} ${configured_headers}
    SOURCES ${sources}
    MAIN src/main.cpp
    )

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
set_SPDLOG_ACTIVE_LEVEL_ifndef()
target_SPDLOG_ACTIVE_LEVEL_definition(${PROJECT_NAME}-object)
target_link_libraries(${PROJECT_NAME}-object PUBLIC spdlog::spdlog)

## Install C++ executable:
install(TARGETS ${PROJECT_NAME})

## Add tests:
include(CTest)
option(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
