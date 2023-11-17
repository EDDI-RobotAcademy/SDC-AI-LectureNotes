#!/bin/bash

echo "Received argument: $TEST_RESULT"

$TEST_RESULT
TEST_EXIT_CODE=$?

echo "Exit code of tests: $TEST_EXIT_CODE"

# 실제 every_unit_test 가 실행되어 테스트가 통과되면
# c_app 을 만들면서 프로그램 컴파일이 완료됨
# 즉 테스트가 실패하면 컴파일 또한 실패됨
if [ $TEST_EXIT_CODE -eq 0 ]; then
    echo "Tests passed. Building c_app..."
    cmake --build . --target c_app
else
    echo "Tests failed. Skipping c_app build."
    exit 1
fi
