#!/usr/bin/bash

echo "First Argument: $1"

mkdir $1
cd $1

CMAKELISTS_CONTENT=$(cat <<END
cmake_minimum_required(VERSION 3.16)
project(test_app C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCE_FILES
        "*.c"
)

add_executable(
    test_app
    ${SOURCE_FILES}
)
END
)

echo "$CMAKELISTS_CONTENT" > CMakeLists.txt

DEFAULT_MAIN_CODE=$(cat <<END
#include <stdio.h>

int main (void)
{

    return 0;
}
END
)

echo "$DEFAULT_MAIN_CODE" > main.c

code .
