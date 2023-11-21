
include(FetchContent)
include(GNUInstallDirs)

# Declare

## ctre (compile-time-regular-expressions)

set(dep_package_name ctre)
set(dep_package_version 3.8.1)
FetchContent_Declare(
    ${dep_package_name}
    URL https://github.com/hanickadot/compile-time-regular-expressions/archive/refs/tags/v${dep_package_version}.zip
    DOWNLOAD_EXTRACT_TIMESTAMP false
    FIND_PACKAGE_ARGS ${dep_package_version}
)

# MakeAvailable

FetchContent_MakeAvailable(ctre)

# Install public dependencies

## ctre

set(dep_package_name ctre)
if(EXISTS ${FETCHCONTENT_BASE_DIR}/${dep_package_name}-build)
    install(TARGETS ${dep_package_name} EXPORT ${PROJECT_NAME}-targets)
    # install_uninstall_script(${PROJECT_NAME}
    #     FILENAME uninstall.cmake
    #     PACKAGE_DIR "${CMAKE_INSTALL_DATADIR}/cmake/${dep_package_name}"
    #     VERSION ${${dep_package_name}_VERSION}
    # )
endif()

clear_install_file_list()
