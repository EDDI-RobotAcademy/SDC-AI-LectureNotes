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

# 기존의 main.c에 병합될 소스 코드들(원래 하던 대로 넣으면 됨)
file(GLOB C_SOURCES
    "simple/*.c"
)

# test로 사용할 파일들은 여기에 정보 배치
# network을 테스트한다면 "tests/network/*.cpp" 와 같은 형태로 만듭니다.
# 결론적으로 test 또한 Domain 관리를 해야하기 때문
file(GLOB CPP_TEST_SOURCES
    "tests/*.cpp"
)

add_library(logic_lib ${C_SOURCES})

# Test executable (C and C++)
add_executable(every_unit_test ${CPP_TEST_SOURCES} "tests/test_main.cpp" ${C_SOURCES})
target_link_libraries(every_unit_test PRIVATE ${GTEST_LIBRARIES} pthread logic_lib)

add_test(NAME every_unit_test COMMAND every_unit_test)
set_tests_properties(every_unit_test PROPERTIES FAIL_REGULAR_EXPRESSION ".*[Ff]ail.*")

# Custom command to check test results and build c_app accordingly
add_custom_command(
    TARGET every_unit_test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Checking test results..."
    COMMAND ${CMAKE_COMMAND} -E env TEST_RESULT=$<TARGET_FILE:every_unit_test> ${CMAKE_CURRENT_SOURCE_DIR}/build_script.sh
    COMMAND_ERROR_IS_FATAL
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running every_unit_test and building c_app if tests pass..."
    VERBATIM
)

file(GLOB MAIN_SOURCES
    "*.c"
)

add_executable(
    c_app
    ${C_SOURCES}
    ${MAIN_SOURCES}
)

add_custom_target(run
    DEPENDS every_unit_test
)
