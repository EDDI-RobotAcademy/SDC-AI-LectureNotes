cmake_minimum_required(VERSION 3.26)
project(cpp_class_questions)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_class_questions main.cpp
        dice/dice.cpp
        dice/dice.h
        player/Player.cpp
        player/Player.h
        board/Board.cpp
        board/Board.h
        vector/Vector.cpp
        vector/Vector.h
        array/Array.cpp
        array/Array.h
        order/Order.cpp
        order/Order.h
        displacement/Displacement.cpp
        displacement/Displacement.h
        Cartesian/Cartesian.cpp
        Cartesian/Cartesian.h)
