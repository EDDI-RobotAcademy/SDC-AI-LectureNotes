cmake_minimum_required(VERSION 3.16)
project(test_app C CXX)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)

if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()

# C source files
file(GLOB C_SOURCES
    "simple/*.c"
)

# C++ test source files
file(GLOB CPP_TEST_SOURCES
    "tests/*.cpp"
)

# Create a library from the shared C source files
add_library(simple_lib ${C_SOURCES})

# Test executable (C and C++)
add_executable(every_unit_test ${CPP_TEST_SOURCES} "tests/test_main.cpp" ${C_SOURCES})
target_link_libraries(every_unit_test PRIVATE ${GTEST_LIBRARIES} pthread simple_lib)

add_test(NAME every_unit_test COMMAND every_unit_test)
set_tests_properties(every_unit_test PROPERTIES FAIL_REGULAR_EXPRESSION ".*[Ff]ail.*")

# Main application (C)
file(GLOB MAIN_SOURCES
    "*.c"
)

add_executable(
    c_app
    ${C_SOURCES}
    ${MAIN_SOURCES}
)

# Link the main application with the simple library
target_link_libraries(c_app PRIVATE simple_lib)
