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
        matrix/Matrix.cpp
        matrix/Matrix.h
        orthogonal/Orthogonal.cpp
        orthogonal/Orthogonal.h
        order/Order.cpp
        order/Order.h
        spherical/Spherical.cpp
        spherical/Spherical.h
        displacement/Displacement.cpp
        displacement/Displacement.h
        triangle/Triangle.cpp
        triangle/Triangle.h
        utility/Random_generator.cpp
        utility/Random_generator.h
        utility/System_changer.cpp
        utility/System_changer.h
)
