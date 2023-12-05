//
// Created by eddi on 23. 12. 1.
//

#ifndef CLASS_TEST_MATRIX_H
#define CLASS_TEST_MATRIX_H


class Matrix {
private:
    int i;
    int j;
    int k;

public:
    int getMatrixA();
    int getMatrixB();
    int getMatrixC();
    void productMatrix(Matrix, Matrix);
    void reverseMatrix(Matrix, Matrix);
};


#endif //CLASS_TEST_MATRIX_H
