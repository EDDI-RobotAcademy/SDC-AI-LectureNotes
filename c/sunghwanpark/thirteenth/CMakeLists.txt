cmake_minimum_required(VERSION 3.16)
project(test_app C)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS " -g")

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCE_FILES
        "*.c"
        "file_io/*.c"
        "format_test/*.c"
)

add_executable(
    test_app
    ${SOURCE_FILES}
)
