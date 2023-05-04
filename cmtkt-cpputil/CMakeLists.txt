cmake_minimum_required(VERSION 3.23)
# rm -rf /tmp/local/ /tmp/cpputil_build/ && cmake_test_full_install

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

check_cmake_binary_dir()
set_build_type_ifndef()

# C++ PROJECT

project(cmtkt-cpputil VERSION 0.1.0
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

set(library_ns "cmtkt")
set(library_name "cpputil")

# Generated headers:
string(JOIN "_" library_macro_prefix ${library_ns} "${library_name}")
generate_macro_version_header(generated_version_header ${library_macro_prefix} ${library_name}/version.hpp)
# generate_macro_version_header(generated_version_header ${library_ns} ${library_name} version.hpp ${PROJECT_VERSION})

# Headers:
set(headers
include/cpputil/cpputil.hpp
)

# Sources:
set(sources
src/cpputil.cpp
)

# Add C++ library:
add_cpp_library(
  PUBLIC
  SHARED ${PROJECT_NAME}
  STATIC ${PROJECT_NAME}-static
  HEADERS ${headers} ${generated_version_header} # ${configured_headers}
  SOURCES ${sources}
  CXX_STANDARD 20
)

# Link C++ targets:
find_package(TBB 2021 REQUIRED CONFIG)
cpp_library_link_libraries(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  PUBLIC TBB::tbb
)

# Install C++ library:
install_cpp_library(
  SHARED ${PROJECT_NAME} 
  STATIC ${PROJECT_NAME}-static 
  EXPORT ${PROJECT_NAME}-targets
)

# Install project package
install_library_package(${PROJECT_NAME}
                        INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in
                        UNINSTALL_SCRIPT
)

# Add examples:
option(BUILD_${PROJECT_NAME}_EXAMPLES "Build appt examples or not" OFF)
if(BUILD_${PROJECT_NAME}_EXAMPLES)
    add_subdirectory(example)
endif()

# Add tests:
option(BUILD_${PROJECT_NAME}_TESTS "Build appt examples or not" OFF)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
