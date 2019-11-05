#!/bin/bash

# Travis example for C++ by Rafał Pocztarski
# For more languages and info see:
# https://github.com/rsp/travis-hello#readme

tn=1
clearFiles(){
    echo Clearing all generated/previous files
    rm -rf ./*.run
}

cd C++/tests/problems

clearFiles

g++ -std=c++14 *.cpp -o "tests.run"
exec ./tests.run -s

echo ALL TESTS PASSED
