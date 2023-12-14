cmake_minimum_required(VERSION 3.10)
project(gogo)

set(CMAKE_CXX_STANDARD 17)

file(GLOB CPP_SOURCES

)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} gtest_main.cpp ${CPP_SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)
include_directories(${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread ${LIBMYSQLCLIENT_LIBRARIES})

