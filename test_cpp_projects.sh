#!/usr/bin/env bash

format="{bold}{blue}"
commandf "$format" rm -rf /tmp/local \
&& commandf "$format" cmake_test_install ./cppexe \
&& commandf "$format" cmake_test_full_install ./cpphutil \
&& commandf "$format" cmake_test_full_install ./cmtk_tests-cpp_util \
&& echo "SUCCESS" && bell -b && exit 0

echo "FAIL"
tocsin -b
exit 1
