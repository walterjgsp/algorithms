#!/bin/bash

# Travis example for C++ by Rafał Pocztarski
# For more languages and info see:
# https://github.com/rsp/travis-hello#readme

tn=1
clearFiles(){
    echo Clearing all generated files
    rm -rf ./*.run
}
t() {
    echo Test $tn $@
}
pass() {
    echo Test $tn OK
    tn=$(($tn+1))
}

fail() {
    echo Test $tn FAILED
    clearFiles
    exit 1
}

cd tests/C++/problems

for file in *
do
    g++ -std=c++14 $file -o "$file.run"
    exec ./$file.run
done

echo ALL TESTS PASSED
