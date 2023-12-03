#include <iostream>
#include <iomanip>
#include <cmath>
#include <thread>
#include "vector/Vector.h"
#include "matrix/Matrix.h"
#include "inhomogeneous/Coordinate.h"
#include "coordinate/SphericalCoordinate.h"
#include "physics/velocity/Velocity.h"
#include "physics/displacement/Displacement.h"

void vector_example()
{
    Vector v1;
    Vector v2;

    // v1.operator+(v2)
    Vector sum = v1 + v2;
    // v1.operator-(v2)
    Vector sub = v1 - v2;

    // operator<< 이긴하지만
    // 만들다 보니 느끼는 부분은 그냥 printVector()를 만드는 것이 더 좋은 것 같음
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v1 + v2: " << sum << std::endl;
    std::cout << "v1 - v2: " << sub << std::endl;
}

void matrix_example()
{
    // 행렬의 곱셈 특성
    Matrix mat1(2, 3);  // n by m
    Matrix mat2(3, 2);  // m by p
    // n by m * m by p = n by p (앞의 열과 뒤의 행이 같아야 곱셈이 가능함)

    // mat1.operator+(mat2)
    Matrix sum = mat1 + mat2;
    // mat1.operator-(mat2)
    Matrix diff = mat1 - mat2;

    std::cout << "mat1:\n" << mat1 << std::endl;
    std::cout << "mat2:\n" << mat2 << std::endl;
    std::cout << "mat1 + mat2:\n" << sum << std::endl;
    std::cout << "mat1 - mat2:\n" << diff << std::endl;

    std::vector<double> vec{1.0, 2.0, 3.0};
    std::vector<double> result = mat1 * vec;

    std::cout << "mat1 * vec: [";
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << "]\n";

    Matrix product = mat1 * mat2;

    std::cout << "mat1 * mat2:\n" << product << std::endl;
}

void coordinate_example()
{
    Coordinate station(1.0, 2.0, 3.0);
    Coordinate target(4.0, 5.0, 6.0);

    std::cout << "Initial Station: (" << station.x << ", " << station.y << ", " << station.z << ")" << std::endl;
    std::cout << "Initial Target: (" << target.x << ", " << target.y << ", " << target.z << ")" << std::endl;

    for (int i = 0; i < 10; ++i) {
        int randomAxis = static_cast<int>(RandomGenerator::generate()) % 3;
        double angle = RandomGenerator::generate() * 2.0 * M_PI;

        Coordinate rotatedTarget = target.rotate(randomAxis == 0 ? angle : 0.0, randomAxis == 1 ? angle : 0.0, randomAxis == 2 ? angle : 0.0);

        std::cout << "Rotation Angle (" << (randomAxis == 0 ? "X" : (randomAxis == 1 ? "Y" : "Z")) << "): " << angle << std::endl;
        std::cout << "Rotated Target: (" << rotatedTarget.x << ", " << rotatedTarget.y << ", " << rotatedTarget.z << ")" << std::endl;

        double distance = sqrt(pow(rotatedTarget.x - station.x, 2) + pow(rotatedTarget.y - station.y, 2) + pow(rotatedTarget.z - station.z, 2));

        std::cout << "Distance between station and rotated target: " << distance << std::endl;
        std::cout << std::endl;
    }
}

void spherical_example()
{
    SphericalCoordinate sphericalPoint(0.3,
                                       30.0 * M_PI / 180.0,
                                       45.0 * M_PI / 180.0);

    std::cout << "Initial Spherical Coordinates: ";
    sphericalPoint.print();

    auto cartesian_coord = sphericalPoint.toCartesian();
    std::cout << "Cartesian Coordinates: (" << std::get<0>(cartesian_coord) << ", " << std::get<1>(cartesian_coord) << ", " << std::get<2>(cartesian_coord) << ")\n";
}

void displacement_example()
{
    Displacement initialDisplacement(RandomGenerator::generate(-15, 15), 45);
    std::cout << "초기 " << initialDisplacement.getDisplacementInfo() << std::endl;

    double timeInterval = 0.01;

    for (int i = 1; i <= 10; ++i) {
        float randomDisplacement = RandomGenerator::generate(-15, 15);

        // 원래 방향도 바꿔야 하지만 이 부분은 대충합시다
        Displacement currentDisplacement(randomDisplacement, 45);
        std::cout << "현재 감지된 미사일 " << currentDisplacement.getDisplacementInfo() << std::endl;

        Velocity velocityObj = Displacement::calculateVelocity(initialDisplacement, currentDisplacement, timeInterval);
        std::cout << "파악된 미사일 " << velocityObj.getVelocityInfo() << std::endl;

        initialDisplacement = currentDisplacement;

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    vector_example();
    std::cout << "=======================================================" << std::endl;
    matrix_example();
    coordinate_example();
    spherical_example();
    // lim delta_h->0 [f(x + delta_h) - f(x)] / delta_h
    displacement_example();

    return 0;
}
