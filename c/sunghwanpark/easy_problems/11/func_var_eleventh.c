#include "func_var_eleventh.h"

// 11. 10진수 33에 ~연산을 취해서 그 결과값을 알아보자!
// (편법을 쓰지말고 2의 보수등을 취해서 구체적으로 서술하기!)

int test_twos_complement(int number)
{
    int tmp_number = ~ number;
    return tmp_number;
}

// +1 -1 =0 

// 0000 0001 => 1 
// 1000 0001 => -1 이라 가정 
// -----------------
// 1000 0010 => ???

//  0000 0001 => 1
//  1111 1111 => -1 
// ------------------
// 1 0000 0000 => 0 

// 0000 0010 0010  => 34 
// 0000 0010 0001  => 33 
// 1111 1101 1110  => NOT 33 = ? = -x 
// 위의 숫자에 뭔가를 더 했을 때 0이 되면 x 

// 1111 1101 1110 => NOT 33 = ? = -x = -34 
// 0000 0010 0010 => 34 = x 