#!/bin/bash

set -e
set -x

mkdir -p build && cd build
rm -rf *
cmake ..
make -j
