cmake_minimum_required(VERSION 3.23)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

#-----
# PROJECT

check_cmake_binary_dir()
set_build_type_ifndef()

#-----
# C++ PROJECT

project(cpphutil
        VERSION 0.1.0
#        DESCRIPTION ""
#        HOMEPAGE_URL ""
        LANGUAGES CXX)

message(STATUS "BUILD   : ${CMAKE_BUILD_TYPE}")
message(STATUS "CPPCOMP : ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION}")

#-----
include(CTest)

# Generated headers:
generate_macro_version_header(generated_version_header ${PROJECT_NAME} ${PROJECT_NAME}/version.hpp)

# Headers:
set(headers
  include/cpphutil/cpphutil.hpp
)

# Add C++ library
add_cpp_library(
    PUBLIC
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${generated_version_header}
    CXX_STANDARD 20
    NAMESPACE cmtkt::
)

# Link targets:
find_package(TBB 2021 REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME} INTERFACE TBB::tbb)

# Install C++ library
install_cpp_library(
    HEADER_ONLY ${PROJECT_NAME} 
    EXPORT ${PROJECT_NAME}-targets
    NAMESPACE cmtkt::
)

# Install package
install_library_package(${PROJECT_NAME}
                        INPUT_PACKAGE_CONFIG_FILE CMake-package-config.cmake.in
                        UNINSTALL_SCRIPT
)

option_or_set_ifdef(${PROJECT_NAME}_BUILD_EXAMPLES "Build appt examples or not" OFF BUILD_ARBA_EXAMPLES)
if(${PROJECT_NAME}_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

option_or_set_ifdef(${PROJECT_NAME}_BUILD_TESTS "Build appt examples or not" OFF BUILD_ARBA_EXAMPLES)
if(${PROJECT_NAME}_BUILD_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()

#-----
