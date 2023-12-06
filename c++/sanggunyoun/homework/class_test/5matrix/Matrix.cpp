//
// Created by eddi on 23. 12. 1.
//

#include <iostream>
#include "Matrix.h"

std::cout<< "자~! 행크열 확인 " << std::endl;
//std::cout << "백크터!" << std::endl;
 int i;
 int j;
 int A[2][2] = { {1, 6}, {5, 0} };
 int B[2][2] ={ {7, 2}, {9, 22} };
 int C[2][2] ={0};

// 연산작업
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
