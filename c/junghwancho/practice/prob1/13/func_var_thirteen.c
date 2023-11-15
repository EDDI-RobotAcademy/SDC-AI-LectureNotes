/*13. main() 함수 안에서
    인자값 2개를 가지는 doit(), letsgo() 함수를 호출
    doit() 함수는 인자값 2개를 % 연산한 결과를 반환
    letsgo() 함수는 인자값 2개를 + 연산한 결과를 반환
    doit()의 결과값과 letsgo()의 결과값을 곱한 결과를 출력하시오.*/
    
    // doit = 인자값 2개
    // letsgo = 인자값 2개
    // doit = 2개로 % 연산 및 결과 리턴 = 함수 1
    // letsgo = 2개로 + 연산 및 결과 리턴 = 함수 2
    // doit 과 letsgo 결과값 곱한 결과 출력 = 함수 c

    #include "func_var_thirteen.h"

    int doit(int num1, int num2)
    {
        return num1 % num2;
    }

    int letsgo(int num3, int num4)
    {
        return num3 + num4;
    }

    int multiply_doit_and_letsgo(int doit_result, int letsgo_result)
    {
        return doit_result * letsgo_result;
    }


    