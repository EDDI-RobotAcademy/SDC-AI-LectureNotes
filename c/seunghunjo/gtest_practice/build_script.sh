#!/bin/bash

# Print the received argument
echo "Received argument: $TEST_RESULT"

# Run the tests and capture the exit code
$TEST_RESULT
TEST_EXIT_CODE=$?

# Print the exit code of the tests
echo "Exit code of tests: $TEST_EXIT_CODE"

# Check the exit code of the tests
if [ $TEST_EXIT_CODE -eq 0 ]; then
    # Build c_app if tests pass
    echo "Tests passed. Building c_app..."
    cmake --build . --target c_app
else
    echo "Tests failed. Skipping c_app build."
    exit 1
fi