cmake_minimum_required(VERSION 3.16)
project(class_test)

set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

add_executable(class_test main.cpp
        dice/Dice.cpp
        dice/Dice.h
        player/Player.cpp
        player/Player.h
        board/controller/BoardController.cpp
        board/controller/BoardController.h
        board/service/BoardService.h
        board/service/response/BoardResponse.cpp
        board/service/response/BoardResponse.h
        board/service/BoardServiceImpl.cpp
        board/service/BoardServiceImpl.h
        board/entity/Board.cpp
        board/entity/Board.h
        board/repository/BoardRepository.h
        mysql/DbProcess.cpp
        mysql/DbProcess.h
        board/repository/BoardRepositoryImpl.cpp
        board/repository/BoardRepositoryImpl.h
        matrix/Matrix.cpp
        board/insert/BoardInsert.h
        board/insert/BoardInsertmpl.cpp
        board/insert/BoardInsertmpl.h
)

target_include_directories(class_test PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(class_test PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})