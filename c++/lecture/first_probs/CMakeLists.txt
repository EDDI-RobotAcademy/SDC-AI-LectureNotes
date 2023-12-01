cmake_minimum_required(VERSION 3.24)
project(first_probs)

set(CMAKE_CXX_STANDARD 17)

add_executable(first_probs main.cpp
        vector/Vector.cpp
        vector/Vector.h
        utility/RandomGenerator.cpp
        utility/RandomGenerator.h
        matrix/Matrix.cpp
        matrix/Matrix.h
        inhomogeneous/Coordinate.cpp
        inhomogeneous/Coordinate.h
        coordinate/SphericalCoordinate.cpp
        coordinate/SphericalCoordinate.h
        physics/displacement/Displacement.cpp
        physics/displacement/Displacement.h
        physics/velocity/Velocity.cpp
        physics/velocity/Velocity.h
)
