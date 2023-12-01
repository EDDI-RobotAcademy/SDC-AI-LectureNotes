//
// Created by eddi on 23. 11. 30.
//

#include "Matrix.h"

#include <utility>
#include <iostream>

Matrix::Matrix(int _row, int _column) : row(_row), column(_column) {
    for(int i = 0; i < _row ; i++){
        for(int j = 0; j < _column; j++){
            matrix[i][j] = 0;
        }
    }

    std::cout << "빈 행렬 생성 완료~ " << row << "x" << column << std::endl;
}

Matrix::~Matrix() {

}

int Matrix::getMatrixRow() {
    return row;
}

int Matrix::getMatrixColumn() {
    return column;
}

Matrix::Matrix(std::vector<std::vector<int>> _matrix) :  matrix(std::move(_matrix)) {
        row = matrix.size();
        column = matrix[0].size();
        std::cout << "행렬로 행렬 생성 완료~ " << row << "x" << column << std::endl;
}

void Matrix::matrixSum(Matrix & _matrixToSum) {
    for(int i = 0; i < row ; i++){
        for (int j = 0; j < column; j++)
            matrix[i][j] = matrix[i][j] + _matrixToSum.matrix[i][j];

    }
}





