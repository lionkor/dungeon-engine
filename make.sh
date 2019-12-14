#!/bin/bash
cd bin
rm -v dungeon-engine
cmake -DCMAKE_BUILD_TYPE=Debug -S ..
make -j 9
cd ..
