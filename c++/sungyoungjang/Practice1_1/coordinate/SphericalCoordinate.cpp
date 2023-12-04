//
// Created by eddi on 23. 12. 1.
//

#include "SphericalCoordinate.h"
#include <cmath>
#include <iostream>
// radius : 반경, azimuth : 고각, elevation : 방위각 ex: azimuth 주포탑 포신 위아래로 elevation 포탑 회전
SphericalCoordinate::SphericalCoordinate(double radius, double azimuth, double elevation)
        : radius(radius), azimuth(azimuth), elevation(elevation) {}
//toCartesian : 위의 각도및 좌표를 수치로 치환
// 이것들은 필수 외워 진짜 외워
std::tuple<double, double, double> SphericalCoordinate::toCartesian() const {
    double x = radius * sin(elevation) * cos(azimuth);
    double y = radius * sin(elevation) * sin(azimuth);
    double z = radius * cos(elevation);
    return std::make_tuple(x, y, z);
}

void SphericalCoordinate::print() const {
    std::cout << "Radius: " << radius << ", azimuth: " << azimuth << ", elevation: " << elevation << std::endl;
}
