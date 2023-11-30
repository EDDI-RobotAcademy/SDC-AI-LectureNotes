cmake_minimum_required(VERSION 3.26)
project(class_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(class_test main.cpp
        dice/Dice.h
        dice/Dice.cpp
        player/Player.cpp
        post/Post.h
        post/Post.cpp
        vector/Vector.h
        vector/Vector.cpp)
