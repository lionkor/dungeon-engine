#!/bin/bash

mkdir -p bin include lib

if [ ! -d String ] || [ ! -d SFML ] || [ ! -d glew ] || [ ! -d glfw ]; then
    git submodule update --init
    rm -r include lib
fi

git submodule update

if [ ! -s include/SFML ]; then
    cd SFML
    cmake . -DBUILD_SHARED_LIBS=false
    make -j5
    cd ..
    ln -s ${PWD}/SFML/lib/* lib/
    ln -s ${PWD}/SFML/include/* include/
fi

if [ ! -s include/String ]; then
    cd String
    mkdir -p bin
    cd bin
    cmake -S ..
    make
    cd ../..
    ln -s ${PWD}/String/include include/String
    ln -s ${PWD}/String/bin/libString.a lib/libString.a
fi

if [ ! -s include/GL ]; then
    cd glew/auto
    make -j5
    cd ..
    make glew.lib.static -j5
    cd ..
    ln -s ${PWD}/glew/lib/* lib/
    ln -s ${PWD}/glew/include/* include/
fi

if [ ! -s include/GLFW ]; then
    cd glfw
    cmake . -DBUILD_SHARED_LIBS=false
    make -j5
    cd ..
    ln -s ${PWD}/glfw/src/libglfw3.a lib/
    ln -s ${PWD}/glfw/include/* include/
fi

cd bin
rm -v dungeon-engine
cmake -DCMAKE_BUILD_TYPE=Debug -S ..
make -j5
cd ..
