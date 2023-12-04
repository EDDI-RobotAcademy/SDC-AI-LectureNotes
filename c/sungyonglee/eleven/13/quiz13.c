#include "quiz13.h"
// 인자값 2개를 가지는 doit(), letsgo() 함수를 호출
// doit() 함수는 인자값 2개를 % 연산한 결과를 반환
// letsgo() 함수는 인자값 2개를 + 연산한 결과를 반환
// doit()의 결과값과 letsgo()의 결과값을 곱한 결과를 출력하시오.
int doit(int number1, int number2)
{
    int result_doit = number1 % number2;
    return result_doit;
}

int letsgo(int number3, int number4)
{
    int result_letsgo = number3 + number4;
    return result_letsgo;
}

/*
int quiz13_result (result_doit, result_letsgo)
{
    printf("13-3. result = %d\n", result_doit * result_letsgo);
    return result_doit * result_letsgo;
}
*/