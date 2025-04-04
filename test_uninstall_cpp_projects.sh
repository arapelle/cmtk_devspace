#!/usr/bin/env bash

format="{bold}{blue}#> {*}"

install_prefix="/tmp/local"
lib_subdir="lib"
cmake_subdir="${lib_subdir}/cmake"

project_names=(
    "cmtk_tests-cpp_hutil"
    "cmtk_tests-cpp_util"
    "cmtk_tests-rsc_lib"
    "alphabet-alpha"
    "alphabet-alphabet"
    "lymerenide"
    "resorice"
)

for ((i = 0; i < ${#project_names[@]}; ++i))
do
    cmake_uninstall_fpath="$install_prefix/$cmake_subdir/${project_names[$i]}/uninstall.cmake"
    if [ -f "$cmake_uninstall_fpath" ]
    then
        commandf "$format" cmake -P "$cmake_uninstall_fpath"
        if (($? != 0))
        then
            echo "FAIL"
            tocsin -b
            exit 1
        fi
    fi
done

echo "SUCCESS" && bell -b && exit 0
