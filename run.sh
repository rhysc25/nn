#!/bin/bash
set -e

if [ $OSTYPE == "msys" ]; then
    rm -rf build
    cmake -B build
    cmake --build build
    ./build/Debug/src.exe
else 
    rm -rf build
    cmake -S . -B build -G "Unix Makefiles"
    cmake --build build
    ./build/src/model/mlp
fi