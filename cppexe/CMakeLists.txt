cmake_minimum_required(VERSION 3.23)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../)

include(CMakePrintHelpers)
include(cmtk/CppExecutableProject)

#-----
# PROJECT

check_cmake_binary_dir()
set_build_type_ifndef()

#-----
# C++ PROJECT

project(cppexe
        VERSION 0.1.0
#        DESCRIPTION ""
#        HOMEPAGE_URL ""
        LANGUAGES CXX)

message(STATUS "BUILD   : ${CMAKE_BUILD_TYPE}")
message(STATUS "CPPCOMP : ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION}")

#-----
include(CTest)

# Headers:
set(headers
    include/cppexe/cppexe.hpp
)

# Sources:
set(sources
    src/cppexe.cpp
    src/main.cpp
)

# Add C++ library
add_cpp_executable(${PROJECT_NAME}
    CXX_STANDARD 17
    INCLUDE_DIRECTORIES include
    VERSION_HEADER "version.hpp"
    HEADERS ${headers}
    SOURCES ${sources}
    )

install(TARGETS ${PROJECT_NAME})

#-----
