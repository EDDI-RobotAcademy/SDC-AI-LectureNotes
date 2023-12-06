cmake_minimum_required(VERSION 3.26)
project(class_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(class_test main.cpp
        1dice/Dice.cpp
        1dice/Dice.h
        2player/Player.cpp
        2player/Player.h
        3board/Board.cpp
        3board/Board.h
        4vector/Vector.cpp
        4vector/Vector.h
        5matrix/Matrix.cpp
        5matrix/Matrix.h


)
