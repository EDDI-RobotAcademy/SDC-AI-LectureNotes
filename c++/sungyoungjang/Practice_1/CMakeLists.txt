cmake_minimum_required(VERSION 3.26)
project(Practice_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practice_1 main.cpp
        01_Dice/Dice.cpp
        01_Dice/Dice.h
        02_Player/Player.cpp
        02_Player/Player.h
        03_Post/Post.cpp
        03_Post/Post.h
        04_Vector/Vector.cpp
        04_Vector/Vector.h
)
