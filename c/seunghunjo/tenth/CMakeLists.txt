cmake_minimum_required(VERSION 3.16)
project(test_app C)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCE_FILES
        "*.c"
        "utility/*.c"
        "vector/adapter/in/api/*.c"
        "vector/adapter/in/api/random_operation/*.c"
        "vector/adapter/in/api/request/*.c"
        "vector/adapter/out/in_memory/*.c"
        "vector/adapter/out/in_memory/store/*.c"
        "vector/adapter/out/in_memory/data/*.c"
        "vector/application/services/*.c"
        "vector/application/services/add/*.c"
        "vector/application/services/sub/*.c"
        "vector/domain/model/*.c"
)

add_executable(
    test_app
    ${SOURCE_FILES}
)
