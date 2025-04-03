#!/usr/bin/env bash

format="{bold}{blue}"
commandf "$format" rm -rf /tmp/local

project_cmds=(
    "cmake_test_install      ./projects/cmtk_tests/cmtk_tests-cpp_exe"
    "cmake_test_full_build   ./projects/cmtk_tests/cmtk_tests-cpp_texe"
    "cmake_test_full_install ./projects/cmtk_tests/cmtk_tests-cpp_hutil"
    "cmake_test_full_install ./projects/cmtk_tests/cmtk_tests_pro-cpp_utility"
    "cmake_test_full_install ./projects/cmtk_tests/cmtk_tests-rsc_lib"
    "cmake_test_full_install ./projects/no_namespace/lymerenide"
    "cmake_test_full_install ./projects/no_namespace/resorice"
)

for ((i = 0; i < ${#project_cmds[@]}; ++i))
do
    commandf "$format" ${project_cmds[$i]}
    if (($? != 0))
    then
        echo "FAIL"
        tocsin -b
        exit 1
    fi
done

echo "SUCCESS" && bell -b && exit 0
