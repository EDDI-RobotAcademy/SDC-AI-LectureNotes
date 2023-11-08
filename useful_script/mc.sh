#!/usr/bin/bash

echo "First Argument: $1"

mkdir $1
cd $1
touch CMakeLists.txt
code .
