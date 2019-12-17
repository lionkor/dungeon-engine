#!/bin/bash

mkdir -p bin include lib

if [ ! -d String ]; then
    echo "String directory not found. Make sure you cloned the repo with --recursive"
    return 1
fi

if [ ! -d SFML ]; then
    echo "SFML directory not found. Make sure you cloned the repo with --recursive"
    return 2
fi

if [ ! -s include/SFML ]; then
    cd SFML
    cmake . -DBUILD_SHARED_LIBS=false
    make -j 9
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

cd bin
rm -v dungeon-engine
cmake -DCMAKE_BUILD_TYPE=Debug -S ..
make -j 9
cd ..
