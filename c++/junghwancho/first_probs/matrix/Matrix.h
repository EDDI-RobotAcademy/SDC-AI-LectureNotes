//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_MATRIX_H
#define FIRST_PROBS_MATRIX_H

#include <iostream>
#include <vector>

class Matrix {

private:
    // private에 있는 애들은 아래 public에 어떻게 선언이 되어 있던(파라미터가 없어도) 다 들어올 수 있다.
    int rows, cols;
    // std:vector = *
    // std::vector<std::vector> = **
    std::vector<std::vector<double>> data;

public:
    Matrix(int rows, int cols);
    ~Matrix();

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    std::vector<double> operator*(const std::vector<double>& vec) const;
    Matrix operator*(const Matrix& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

#endif //FIRST_PROBS_MATRIX_H
