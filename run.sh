#!/bin/bash

if [ $OSTYPE == "msys" ]; then
    cmake -B build
    cmake --build build
    ./build/Debug/nn.exe
else 
    cmake -S . -B build -G "Unix makefiles"
    cmake --build build
    ./build/nn
fi
