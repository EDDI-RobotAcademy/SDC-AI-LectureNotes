//
// Created by eddi on 23. 12. 1.
//

#include <cassert>
#include "Matrix.h"

Matrix& Matrix::matrixAdd (const Matrix& other)
{
    assert (mRows == other.mRows);
    assert (mCols == other.mCols);

    for (size_t row = 0; row < mRows; row ++)
    {
        for (size_t col = 0; col < mCols; col ++)
        {
            mData[row][col] += other.mData[row][col];
        }
    }
    return *this;
}

Matrix& Matrix::matrixSub (const Matrix& other)
{
    assert (mRows == other.mRows);
    assert (mCols == other.mRows);

    for (size_t row = 0; row < mRows; row ++)
    {
        for (size_t col = 0; col < mCols; col ++)
        {
            mData[row][col] += other.mData[row][col];
        }
    }
    return *this;
}