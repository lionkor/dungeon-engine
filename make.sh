#!/bin/bash

mkdir -p bin include lib

if [ ! -d String ]; then
    echo "String directory not found. Make sure you cloned the repo with --recursive"
    return 1
fi

if [ ! -f include/String ]; then
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
