cmake_minimum_required(VERSION 3.16)
project(class_test)

set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

file(GLOB CPP_SOURCES
        "dice/*.cpp"
        "player/*.cpp"
        "board/controller/response_form/*.cpp"
        "board/controller/request_form/*.cpp"
        "board/controller/*.cpp"
        "board/service/response/*.cpp"
        "board/service/request/*.cpp"
        "board/service/*.cpp"
        "board/entity/*.cpp"
        "board/repository/*.cpp"
        "account/entity/*.cpp"
        "account/controller/*.cpp"
        "account/controller/response_form/*.cpp"
        "account/controller/request_form/*.cpp"
        "account/service/*.cpp"
        "account/service/request/*.cpp"
        "account/service/response/*.cpp"
        "account/repository/*.cpp"
        "console_ui/controller/*.cpp"
        "console_ui/service/*.cpp"
        "console_ui/repository/*.cpp"
        "utility/keyboard/*.cpp"
        "mysql/*.cpp"
)

file(GLOB MAIN_SOURCE
        "*.cpp"
)

add_executable(
        class_test
        ${MAIN_SOURCE}
        ${CPP_SOURCES}
)

target_include_directories(class_test PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(class_test PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})
