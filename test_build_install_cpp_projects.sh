#!/usr/bin/env bash

format="{bold}{blue}"
commandf "$format" rm -rf /tmp/local
commandf "$format" cmake_test_install ./projects/cmtk_tests/cmtk_tests-cpp_exe \
&& commandf "$format" cmake_test_full_build ./projects/cmtk_tests/cmtk_tests-cpp_texe \
&& commandf "$format" cmake_test_full_install ./projects/cmtk_tests/cmtk_tests-cpp_hutil \
&& commandf "$format" cmake_test_full_install ./projects/cmtk_tests/cmtk_tests-cpp_util \
&& commandf "$format" cmake_test_full_install ./projects/cmtk_tests/cmtk_tests-rsc_lib \
&& commandf "$format" cmake_test_full_install ./projects/alphabet/alphabet-alphabet \
&& commandf "$format" cmake_test_full_install ./projects/no_namespace/lymerenide \
&& commandf "$format" cmake_test_full_install ./projects/no_namespace/resorice \
&& echo "SUCCESS" && bell -b && exit 0

echo "FAIL"
tocsin -b
exit 1
