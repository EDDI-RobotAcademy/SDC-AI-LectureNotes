#include <stdio.h>

#include "1/func_var_first.h"
#include "2/func_var_second.h"
#include "3/func_var_third.h"
#include "4/func_var_fourth.h"
#include "13/func_var_thirteen.h"
#include "14/func_var_fourteen.h"
#include "15/func_var_fifteen.h"

int main (void)
{
    // 1. 실수와 정수를 입력받고 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력
    printf("1.result:%5.2f\n", multipy_float_and_int(3.7f, 5));
    
    //2. 두 개의 정수(num1, num2)를 입력받고 num1 << num2 값을 구하는 함수를 작성하라
    printf("2. result:%d\n", return_shift_from_two_integer(2, 9));

    // 3. 실수 하나를 입력받아 소수점만 분리하고 또 정수 부분만 분리하는 함수를 작성하시오 (함수 총 2개를 작성하면됨)
    printf("3.1 result:%.2f\n", separate_decimal(3.7f));
    printf("3.2 result:%d\n", separate_int(3.7f));

    // 4. float과 double 자료형의 저장 방식에 대해서 서술하시오.
    // float = 4byte, double = 8byte
    // 확인해보려면 byte size 구해보자
    check_float_double_size(sizeof(float), sizeof(double));

    // 13.
    int num1 = 5;
    int num2 = 5;
    int num3 = 2;
    int num4 = 5;
    printf("13.\ndoit_result:%d\nletsgo_result:%d\n", doit(num1, num2), letsgo(num3, num4));
    printf("multiply_result:%d\n", multiply_doit_and_letsgo(doit(num1, num2), letsgo(num3, num4)));

    // 14.
    check_who_is_bigger(3, 5);
    check_who_is_bigger(6, 3);
    check_who_is_bigger(3, 3);

    // 15. 
    printf("add_int_float_make_it_int:%d\n", add_two_numbers(5, 5.5f));


    return 0;
}
