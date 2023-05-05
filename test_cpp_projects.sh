#!/usr/bin/env bash

format="{bold}{grey}{BLUE}"
commandf "$format" rm -rf /tmp/local \
&& commandf "$format" cmake_test_install ./cppexe \
&& commandf "$format" cmake_test_full_install ./cpphutil \
&& commandf "$format" cmake_test_full_install ./cmtkt-cpputil \
&& echo "SUCCESS" && bell -b && exit 0

echo "FAIL"
tocsin -b
exit 1
