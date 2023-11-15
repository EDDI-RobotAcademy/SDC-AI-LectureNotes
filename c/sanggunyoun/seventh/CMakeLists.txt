cmake_minimum_required(VERSION 3.16)
project(c_app C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_CFKAGS} -g")

set(CMAKE_BUILD_TYPE Debug)


    file(GLOB SOURCE_FILES
        "*.c"
        "led/entity/*.c"
        "account/entity/*.c"
)
     # 여기있는 배열들은 전역
add_executable(
    test_app
    ${SOURCE_FILES}
)