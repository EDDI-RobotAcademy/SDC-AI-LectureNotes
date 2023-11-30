cmake_minimum_required(VERSION 3.26)
project(cpp_test)

set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

file(GLOB CPP_SOURCES
        "api/*.cpp"
        "mysql_test/*.cpp"
)

file(GLOB MAIN_SOURCES
        "*.cpp"
)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

add_executable(
        main_app
        ${CPP_SOURCES}
        ${MAIN_SOURCES}
)

target_include_directories(main_app PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(main_app PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})
