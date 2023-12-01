//
// Created by eddi on 23. 12. 1.
//

#ifndef CLASS_TEST_MATRIX_H
#define CLASS_TEST_MATRIX_H


#include <cstddef>
#include <vector>

class Matrix {

private:
    size_t mRows;
    size_t mCols;
    std::vector<std::vector<float>> mData;

public:
    Matrix& matrixAdd (const Matrix& other);
    Matrix& matrixSub (const Matrix& other);
};


#endif //CLASS_TEST_MATRIX_H
