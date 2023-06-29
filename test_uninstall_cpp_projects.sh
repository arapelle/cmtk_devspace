#!/usr/bin/env bash

format="{bold}{blue}"

install_prefix="/tmp/local"
lib_subdir="lib"
cmake_subdir="${lib_subdir}/cmake"

commandf "$format" cmake -P $install_prefix/$cmake_subdir/cmtk_tests-cpp_hutil/cmake_uninstall.cmake \
&& commandf "$format" cmake -P $install_prefix/$cmake_subdir/cmtk_tests-cpp_util/cmake_uninstall.cmake \
&& commandf "$format" cmake -P $install_prefix/$cmake_subdir/cmtk_tests-alpha/cmake_uninstall.cmake \
&& commandf "$format" cmake -P $install_prefix/$cmake_subdir/cmtk_tests-alphabet/cmake_uninstall.cmake \
&& commandf "$format" cmake -P $install_prefix/$cmake_subdir/lymerenide/cmake_uninstall.cmake \
&& test ! -d $install_prefix/$lib_subdir \
&& echo "SUCCESS" && bell -b && exit 0

echo "FAIL"
tocsin -b
exit 1
