cmake_minimum_required(VERSION 3.26)
project(cpp_gtest)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)

if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()

file(GLOB CPP_SOURCES
        "arithmetic/*.cpp"
        "function/*.cpp"
        "tests/*.cpp"
        "tests/add/*.cpp"
)

file(GLOB MAIN_SOURCES
        "*.cpp"
)

add_executable(
        cpp_gtest
        ${CPP_SOURCES}
        ${MAIN_SOURCES}
        tests/sub/sub_test.cpp
        arithmetic/Sub.cpp
        arithmetic/Sub.h
        function/SampleFunction.cpp
        function/SampleFunction.h
        tests/function/fucntion_test.cpp
)

add_library(logic_lib ${CPP_SOURCES})

add_executable(every_unit_test ${CPP_TEST_SOURCES} "tests/test_main.cpp" ${CPP_SOURCES}
        tests/sub/sub_test.cpp
        tests/function/fucntion_test.cpp)
target_link_libraries(every_unit_test PRIVATE ${GTEST_LIBRARIES} pthread logic_lib)
