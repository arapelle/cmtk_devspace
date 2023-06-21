cmake_minimum_required(VERSION 3.23)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../../)
include(CMakePrintHelpers)
include(cmtk/CppExecutableProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set(PROJECT_NAME "cmtk_tests-cpp_texe")
set(project_namespace "cmtk_tests")
set(project_feature_name "cpp_texe")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")

## Generated/Configured headers:
generate_version_macro_header(generated_version_header 
                              ${project_namespace}_${project_feature_name}
                              ${project_namespace}/${project_feature_name}/version.hpp)

## Headers:
set(headers
    include/${project_namespace}/cpp_texe/cpp_texe.hpp
    include/${project_namespace}/cpp_texe/cpp_texe_main.hpp
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
    HEADERS ${headers} ${generated_version_header}
    SOURCES ${sources}
    MAIN src/main.cpp
    )

## Link C++ targets:
find_package(spdlog 1.8 REQUIRED CONFIG)
set_spdlog_active_level_ifndef()
target_compile_definitions(${PROJECT_NAME}-object PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_${SPDLOG_ACTIVE_LEVEL})
target_link_libraries(${PROJECT_NAME}-object PUBLIC spdlog::spdlog)

## Install C++ executable:
install(TARGETS ${PROJECT_NAME})

## Add tests:
include(CTest)
option(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
