#include <stdio.h>

#include "1/func_var_first.h"
#include "2/func_var_second.h"
#include "3/func_var_third.h"
#include "4/func_var_fourth.h"
#include "5/func_var_fifth.h"
#include "6/func_var_sixth.h"
#include "9/func_var_ninth.h"
#include "10/func_var_tenth.h"
#include "11/func_var_eleventh.h"
#include "13/func_var_thirteenth.h"
#include "14/func_var_fourteenth.h"
#include "15/func_var_fifteenth.h"

int result1;
int result2;

int main (void)
{   // 1번 문제 
    printf("1. result: %.2f\n", multiply_float_and_integer(5,2.0f));
    // 2번 문제 
    printf("2. result: %d\n", return_shift_from_integer(2,5));
    // 3번 문제 
    printf("3-1. result: %.2f\n", return_float_from_float(8.5f));
    printf("3-2. result: %d\n", return_int_from_float(8.5f));
    // 4번 문제 
    check_float_and_double();
    // 5번 문제 
    printf("5. shortcut test: %d\n",shortcut_test(30));
    printf("5. shortcut test: %d\n",shortcut_test(11));
    printf("5. shortcut test: %d\n",shortcut_test(8));
    printf("5. shortcut test: %d\n",shortcut_test(1));
    // 6번 문제
    printf("6. result = %d\n", number_align_with_parameter(10, 1040));

    // 7번 문제: 함수 정의를 main 함수 아래에 적었을 경우, Compile Error가 나는 이유에 대해 기술하시오.
    // 함수 프로토타입을 모르기 때문에 최상단에 함수 프로토타입을 작성하면 문제가 해경됨.  
    
    // 8번 문제: 변수의 정확한 정의에 대해 기술하시오.
    // 특정 데이터 타입의 정보를 저장 할 수 있는 메모리 공간 

    // 9번 문제 
    printf("9-1. overflow = %d\n", test_overflow(125));
    printf("9-2. underflow = %d\n", test_underflow(-125));

    // 10번 문제 
    printf("10-1. 5 & 10 and test: %d\n",and_test(5,10));
    printf("10-2. 5 & 10 or test: %d\n",or_test(5,10));
    printf("10-3. 5 & 10 xor test: %d\n",xor_test(5,10));
    printf("10-4. 5 not test: %d\n",not_test(5));

    // 11번 문제
    printf("11. not 33 function: %d\n",test_twos_complement(33));

    // 12번 문제 
    // Memory 구조 (Stack, Heap, Data, Text)에 대해서 기술하시오. 
    // Stack: 지역 변수 
    // Heap: new, malloc 등의 동적 할당 
    // Data: 정적 변수, 

    // 13번 문제 
    printf("13. result: %d\n", return_doit_and_letsgo(doit(3,7),letsgo(3,7)));

    // 14번 문제 
    result1 = which_one_is_bigger(5,6);
    result2 = which_one_is_bigger(5,5);
   
    printf("14-1. Which one is bigger, 5 or 6? => %d\n", result1);
    
    if(!result2)
    {
        printf("14-2. 숫자 비교 불가 -> 둘의 숫자가 동일함. \n");
    }
    
    // 15번 문제 
    printf("15. 결과 : %d\n",return_integer_from_two_parameters(3,7.7f));
    return 0;
}
