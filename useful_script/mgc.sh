#!/usr/bin/bash

echo "First Argument: $1"

mkdir $1
cd $1
mkdir tests
mkdir sample

SAMPLE_LIB_CODE=$(cat <<END
#include "sample.h"

#include <stdio.h>

void sample(void)
{
	printf("sample\n");
}
END
)

echo "$SAMPLE_LIB_CODE" > sample/sample.c

SAMPLE_LIB_HEADER=$(cat <<END
#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif

void sample(void);

#ifdef __cplusplus
}
#endif

#endif
END
)

echo "$SAMPLE_LIB_HEADER" > sample/sample.h

CMAKELISTS_CONTENT=$(cat <<END
cmake_minimum_required(VERSION 3.16)
project(test_app C CXX)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "\${CMAKE_C_FLAGS} -g")
set(CMAKE_CXX_FLAGS "\${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)

if(GTest_FOUND)
    include_directories(\${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()

file(GLOB C_SOURCES
	"sample/*.c"
)

file(GLOB CPP_TEST_SOURCES
    "tests/*.cpp"
)

add_library(logic_lib \${C_SOURCES})

add_executable(every_unit_test \${CPP_TEST_SOURCES} "tests/test_main.cpp" \${C_SOURCES})
target_link_libraries(every_unit_test PRIVATE \${GTEST_LIBRARIES} pthread logic_lib)

add_test(NAME every_unit_test COMMAND every_unit_test)
set_tests_properties(every_unit_test PROPERTIES FAIL_REGULAR_EXPRESSION ".*[Ff]ail.*")

add_custom_command(
    TARGET every_unit_test
    POST_BUILD
    COMMAND \${CMAKE_COMMAND} -E echo "Checking test results..."
    COMMAND \${CMAKE_COMMAND} -E env TEST_RESULT=$<TARGET_FILE:every_unit_test> \${CMAKE_CURRENT_SOURCE_DIR}/build_script.sh
    COMMAND_ERROR_IS_FATAL
    WORKING_DIRECTORY \${CMAKE_BINARY_DIR}
    COMMENT "Running every_unit_test and building c_app if tests pass..."
    VERBATIM
)

file(GLOB MAIN_SOURCES
    "*.c"
)

add_executable(
    c_app
    \${C_SOURCES}
    \${MAIN_SOURCES}
)

add_custom_target(run
    DEPENDS every_unit_test
)
END
)

echo "$CMAKELISTS_CONTENT" > CMakeLists.txt

DEFAULT_TEST_MAIN_CODE=$(cat <<END
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
END
)

echo "$DEFAULT_TEST_MAIN_CODE" > tests/test_main.cpp

DEFAULT_MAIN_CODE=$(cat <<END
#include <stdio.h>

int main (void)
{
	printf("hi\n");
    return 0;
}
END
)

echo "$DEFAULT_MAIN_CODE" > main.c

TEST_CHECK_SCRIPT_CODE=$(cat <<END
#!/bin/bash

echo "Received argument: \$TEST_RESULT"

\$TEST_RESULT
TEST_EXIT_CODE=\$?

echo "Exit code of tests: \$TEST_EXIT_CODE"

if [ \$TEST_EXIT_CODE -eq 0 ]; then
    echo "Tests passed. Building c_app..."
    cmake --build . --target c_app
else
    echo "Tests failed. Skipping c_app build."
    exit 1
fi
END
)

echo "$TEST_CHECK_SCRIPT_CODE" > build_script.sh

chmod +x build_script.sh

code .
