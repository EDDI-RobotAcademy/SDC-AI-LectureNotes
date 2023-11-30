#!/bin/bash

# Print the received argument
echo "Received argument: $TEST_RESULT"

# Run the tests and capture the exit code
$TEST_RESULT
TEST_EXIT_CODE=$?

# Print the exit code of the tests
echo "Exit code of tests: $TEST_EXIT_CODE"

# 실제 every_unit_test 가 실행되어 테스트가 통과되면
# c_app 을 만들면서 프로그램 컴파일이 완료됨
# Check the exit code of the tests
if [ $TEST_EXIT_CODE -eq 0 ]; then
    # Build c_app if tests pass
    echo "Tests passed. Building c_app..."
    cmake --build . --target c_app
else
    echo "Tests failed. Skipping c_app build."
    exit 1
fi