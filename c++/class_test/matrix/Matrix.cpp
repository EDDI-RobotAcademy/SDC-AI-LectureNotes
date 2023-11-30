//
// Created by eddi on 23. 11. 30.
//

#include "Matrix.h"

Matrix::Matrix(int _row, int _column) : row(_row), column(_column) {

}

Matrix::~Matrix() {

}

int Matrix::getMatrixRow() {
    return row;
}

int Matrix::getMatrixColumn() {
    return column;
}
