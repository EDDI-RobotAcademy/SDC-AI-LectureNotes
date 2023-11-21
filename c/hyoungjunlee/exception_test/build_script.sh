#!/bin/bash

echo "Received argument: $TEST_RESULT"

$TEST_RESULT
TEST_EXIT_CODE=$?

echo "Exit code of tests: $TEST_EXIT_CODE"

if [ $TEST_EXIT_CODE -eq 0 ]; then
    echo "Tests passed. Building c_app..."
    cmake --build . --target c_app
else
    echo "Tests failed. Skipping c_app build."
    exit 1
fi
