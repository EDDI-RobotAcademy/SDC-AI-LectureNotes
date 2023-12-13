//
// Created by eddi on 23. 12. 1.
//

#include "Matrix.h"

#include <iostream>
#include <random>
#include <iomanip>

Matrix::Matrix() {}

void Matrix::getRandom3x3Matrix() {
    std::cout << "Generate Random 3x3 Matrix!" << std::endl;
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Mat3x3[i][j] = distribution(mersenneTwister);
        }
    }
}

void Matrix::showMatrix() {
    for (int i = 0; i < 3; i++) { // row
        for (int j = 0; j < 3; j++) { // column
            std::cout << std::setw(3) << Mat3x3[i][j];
        }
        std::cout << std::endl;
    }
}

void Matrix::showMatrix2() {
    for (int i = 0; i < 3; i++) { // row
        for (int j = 0; j < 3; j++) { // column
            std::cout << std::setw(10) << Mat3x3[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix *Matrix::transposeMatrix() {
    // 복사본 생성
    Matrix copy;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copy.Mat3x3[i][j] = Mat3x3[i][j];
        }
    }
    // 전치
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            Mat3x3[l][k] = copy.Mat3x3[k][l];
        }
    }

    return this;
}

Matrix *Matrix::inverseMatrix() {
    // 복사본 생성
    Matrix copy;
    Matrix result;
    double a, b, c, det3x3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copy.Mat3x3[i][j] = Mat3x3[i][j];
        }
    }
    // 3x3 행렬 결정자 구하기
    a = copy.Mat3x3[0][0] * (copy.Mat3x3[1][1] * copy.Mat3x3[2][2] -
                             copy.Mat3x3[2][1] * copy.Mat3x3[1][2]);
    b = -(copy.Mat3x3[0][1] * (copy.Mat3x3[1][0] * copy.Mat3x3[2][2] -
                             copy.Mat3x3[2][1] * copy.Mat3x3[0][2]));
    c = copy.Mat3x3[0][2] * (copy.Mat3x3[1][0] * copy.Mat3x3[2][1] -
                             copy.Mat3x3[1][1] * copy.Mat3x3[2][0]);
    det3x3 = a+b+c;

    // 전치 행렬 구하기
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            Mat3x3[l][k] = copy.Mat3x3[k][l];
        }
    }

    // 여인자 행렬 구하기
    result.Mat3x3[0][0] = (Mat3x3[1][1]*Mat3x3[2][2] - Mat3x3[1][2]*Mat3x3[2][1]) / det3x3 ;
    result.Mat3x3[0][1] = -(Mat3x3[1][0]*Mat3x3[2][2] - Mat3x3[1][2]*Mat3x3[2][0]) / det3x3 ;
    result.Mat3x3[0][2] = (Mat3x3[1][0]*Mat3x3[2][1] - Mat3x3[1][1]*Mat3x3[2][0]) / det3x3 ;

    result.Mat3x3[1][0] = -(Mat3x3[0][1]*Mat3x3[2][2] - Mat3x3[0][2]*Mat3x3[2][1]) / det3x3 ;
    result.Mat3x3[1][1] = (Mat3x3[0][0]*Mat3x3[2][2] - Mat3x3[0][2]*Mat3x3[2][0]) / det3x3 ;
    result.Mat3x3[1][2] = -(Mat3x3[0][1]*Mat3x3[2][0] - Mat3x3[0][1]*Mat3x3[2][0]) / det3x3 ;

    result.Mat3x3[2][0] = (Mat3x3[0][1]*Mat3x3[1][2] - Mat3x3[0][2]*Mat3x3[1][1]) / det3x3 ;
    result.Mat3x3[2][1] = -(Mat3x3[0][0]*Mat3x3[1][2] - Mat3x3[0][2]*Mat3x3[1][0]) / det3x3 ;
    result.Mat3x3[2][2] = (Mat3x3[0][0]*Mat3x3[1][1] - Mat3x3[0][1]*Mat3x3[1][0]) / det3x3 ;

    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            Mat3x3[m][n] = result.Mat3x3[m][n];
        }
    }

    return this;
}

Matrix::~Matrix() {}