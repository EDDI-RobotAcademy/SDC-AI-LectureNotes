cmake_minimum_required(VERSION 3.16)
project(test_app C)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -lm")

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCE_FILES
        "*.c"
        "extra/*.c"
        "utility/*.c"
        "1/*.c"
        "2/*.c"
        "3/*.c"
        "4/*.c"
        "5/*.c"
        "6/*.c"
        "7/*.c"
        "8/*.c"
        "9/*.c"
        "10/*.c"
        "11/*.c"
        "12/*.c"
)

add_executable(
    test_app
    ${SOURCE_FILES}
)
