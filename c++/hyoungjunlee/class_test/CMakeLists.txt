cmake_minimum_required(VERSION 3.26)
project(class_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(class_test main.cpp
        dice/Dice.cpp
        dice/Dice.h
        player/Player.cpp
        player/Player.h
        post/Post.cpp
        post/Post.h
        vector/Vector.cpp
        vector/Vector.h

)
