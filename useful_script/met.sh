#!/bin/bash

if [ -z "$1" ]; then
    echo "디렉토리 이름이 입력되지 않았습니다. 사용법: $0 <디렉토리이름>"
    exit 1
fi

if [ -d "tests" ]; then
    echo "tests 디렉토리를 찾았습니다."
else
    # tests 디렉토리가 없으면 생성
    mkdir "tests"
    echo "tests 디렉토리를 생성했습니다."
fi

tests_dir="tests"

new_dir_name="$1"
new_dir_path="$tests_dir/$new_dir_name"

# tests 디렉토리 하위에 입력받은 이름으로 디렉토리 생성
mkdir "$new_dir_path"

echo "$new_dir_path 디렉토리를 생성했습니다."

gtest_main_content="#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}"

echo "$gtest_main_content" > "$new_dir_path/gtest_main.cpp"
echo "$new_dir_path/gtest_main.cpp 파일을 생성했습니다."

# CMakeLists.txt 생성
cmakelists_content="cmake_minimum_required(VERSION 3.10)
project($new_dir_name)

set(CMAKE_CXX_STANDARD 17)

# Locate GTest
find_package(GTest REQUIRED)

# Include directories
include_directories(\${GTEST_INCLUDE_DIRS})

# Add executable
add_executable(\${PROJECT_NAME} gtest_main.cpp)

# Link against GTest
target_link_libraries(\${PROJECT_NAME} \${GTEST_LIBRARIES} pthread)

# MySQL libraries and includes
find_package(MySQL REQUIRED)
include_directories(\${MYSQL_INCLUDE_DIRS})

# Link against MySQL
target_link_libraries(\${PROJECT_NAME} \${MYSQL_LIBRARIES})
"

echo "$cmakelists_content" > "$new_dir_path/CMakeLists.txt"
echo "$new_dir_path/CMakeLists.txt 파일을 생성했습니다."
