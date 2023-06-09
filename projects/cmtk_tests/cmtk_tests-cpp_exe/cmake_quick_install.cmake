# cmake -P cmake_quick_install.cmake

function(get_script_args script_args)
    set(sc_args)
    set(start_found False)
    foreach(argi RANGE ${CMAKE_ARGC})
        set(arg ${CMAKE_ARGV${argi}})
        if(start_found)
            list(APPEND sc_args ${arg})
        endif()
        if("${arg}" STREQUAL "--")
            set(start_found True)
        endif()
    endforeach()
    set(${script_args} ${sc_args} PARENT_SCOPE)
endfunction()

get_script_args(args)
set(options "")
set(params DIR BUILD)
set(lists "")
cmake_parse_arguments(ARG "${options}" "${params}" "${lists}" ${args})

set(project "cpp_exe")

if(WIN32)
    set(temp_dir $ENV{TEMP})
elseif(UNIX)
    set(temp_dir /tmp)
else()
    message(FATAL_ERROR "No temporary directory found!")
endif()

file(TO_NATIVE_PATH "/" path_sep)
set(src_dir ${CMAKE_CURRENT_LIST_DIR})
set(build_dir ${temp_dir}${path_sep}${project}-build)
set(error_file ${build_dir}${path_sep}quick_install_error)

if(EXISTS ${error_file})
    message(STATUS "Previous call to quick_install.cmake failed. Cleaning...")
    file(REMOVE_RECURSE ${build_dir})
endif()

message(STATUS "*  CONFIGURATION")
if(ARG_BUILD)
    list(APPEND conf_args -DCMAKE_BUILD_TYPE=${ARG_BUILD})
else()
    list(APPEND conf_args -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE})
endif()
if(ARG_DIR)
    list(APPEND conf_args -DCMAKE_INSTALL_PREFIX=${ARG_DIR})
endif()
execute_process(COMMAND ${CMAKE_COMMAND} ${conf_args} -S ${src_dir} -B ${build_dir}  RESULT_VARIABLE cmd_res)
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
    return()
endif()

message(STATUS "*  BUILD")
execute_process(COMMAND ${CMAKE_COMMAND} --build ${build_dir}  RESULT_VARIABLE cmd_res)
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
    return()
endif()

message(STATUS "*  INSTALL")
execute_process(COMMAND ${CMAKE_COMMAND} --install ${build_dir})
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
endif()
