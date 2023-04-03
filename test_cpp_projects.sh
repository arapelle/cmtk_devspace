#!/usr/bin/env bash

command rm -rf /tmp/local \
&& command cmake_test_install ./cppexe \
&& command cmake_test_full_install ./cpphutil \
&& command cmake_test_full_install ./cmtkt-cpputil \
&& echo "SUCCESS" && bell && exit 0

echo "FAIL"
exit 1
