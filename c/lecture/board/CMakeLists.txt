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

file(GLOB C_SOURCES
    "board/adapter/input/request_form/*.c"
    "board/adapter/input/handler/list/*.c"
    "board/adapter/input/handler/register/*.c"
    "board/adapter/input/handler/read/*.c"
    "board/adapter/input/handler/modify/*.c"
    "board/adapter/input/handler/remove/*.c"
    "board/adapter/input/*.c"
    "board/application/services/request/*.c"
    "board/application/services/response/*.c"
    "board/application/services/response/list/*.c"
    "board/application/services/handler/get_list/*.c"
    "board/application/services/handler/create/*.c"
    "board/application/services/handler/get_one/*.c"
    "board/application/services/handler/modify/*.c"
    "board/application/services/handler/remove/*.c"
    "board/application/services/*.c"
    "board/adapter/output/file/repository/*.c"
    "board/adapter/output/file/handler/find_all/*.c"
    "board/adapter/output/file/handler/save/*.c"
    "board/adapter/output/file/handler/find_by_id/*.c"
    "board/adapter/output/file/handler/delete_by_id/*.c"
    "board/adapter/output/file/*.c"
    "board/domain/model/*.c"
    "ui/console/service/*.c"
    "ui/console/service/handler/create/*.c"
    "ui/console/service/handler/list/*.c"
    "ui/console/service/handler/read/*.c"
    "ui/console/service/handler/modify/*.c"
    "ui/console/service/handler/remove/*.c"
    "ui/console/service/handler/exit/*.c"
    "ui/console/user_keyboard/*.c"
    "ui/console/window/*.c"
    "in_memory/board/*.c"
    "file/raw_io/*.c"
    "file/*.c"
    "utility/*.c"
)

file(GLOB CPP_TEST_SOURCES
    "tests/*.cpp"
    "tests/board/domain/model/*.cpp"
    "tests/board/adapter/input/*.cpp"
    "tests/board/adapter/output/file/handler/save/*.cpp"
    "tests/ui/console/service/*.cpp"
)

add_library(logic_lib ${C_SOURCES})

add_executable(every_unit_test ${CPP_TEST_SOURCES} "tests/test_main.cpp" ${C_SOURCES})
target_link_libraries(every_unit_test PRIVATE ${GTEST_LIBRARIES} pthread logic_lib)

add_test(NAME every_unit_test COMMAND every_unit_test)
set_tests_properties(every_unit_test PROPERTIES FAIL_REGULAR_EXPRESSION ".*[Ff]ail.*")

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
    board_app
    ${C_SOURCES}
    ${MAIN_SOURCES}
)

add_custom_target(run
    DEPENDS every_unit_test
)
