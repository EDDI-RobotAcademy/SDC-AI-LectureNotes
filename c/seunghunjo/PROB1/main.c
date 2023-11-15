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

int main (void)
{
    int result;
    int number = 3, number2 = 7;

    // 1번 문제
    printf("1. result = %5.2f\n", just_multiple_float_and_integer(3, 7.7f));

    // 2번 문제
    printf("2. result = %d\n", return_shift_from_two_integer(2, 9));

    // 3번 문제
    printf("3-1. result = %5.2f\n", separate_float_from_input(7.7f));
    printf("3-2. result = %d\n", separate_integer_from_input(7.7f));

    // 4번 문제
    // float은 4byte, double은 8byte
    check_float_double_size();

    // 5번 문제
    printf("5. result = %d\n", shortcut_test(30));
    printf("5. result = %d\n", shortcut_test(11));
    printf("5. result = %d\n", shortcut_test(8));
    printf("5. result = %d\n", shortcut_test(1));

    // 6번 문제
    printf("6. result = %d\n", number_align_with_parameter(10, 1040));
    printf("6. result = %d\n", number_align_with_parameter(5, 776));
    printf("6. result = %d\n", number_align_with_parameter(2, 123));
    printf("6. result = %d\n", number_align_with_parameter(5, 64));

    // 7번 문제
    // 함수 프로토타입을 모르기 때문에 최상단에 함수 프로토타입을 작성하면 문제가 해결됨

    // 8번 문제
    // 특정 데이터 타입의 정보를 저장 할 수 있는 메모리 공간

    // 9번 문제
    printf("9. overflow = %d\n", test_overflow(127));
    printf("9. underflow = %d\n", test_underflow(-128));

    // 10번 문제
    printf("10. 5 and 14 = %d\n", and_data(5, 14));
    printf("10. 12 or 10 = %d\n", or_data(12, 10));
    printf("10. 5 xor 10 = %d\n", xor_data(5, 10));
    printf("10. not 6 = %d\n", not_data(6));

    // 11번 문제
    printf("11. not 연산: %d\n", check_not_data(33));

    // 12번 문제
    // Memory 구조(Stack, Heap, Data, Text)에 대해서 기술하시오.
    // Stack: 지역 변수
    // Heap: new, malloc 등의 동적 할당
    // Data: 정적 변수, 전역 변수
    // Text: 기계어

    // 13번 문제
    printf("13. result = %d\n", process_data(
        doit(number, number2),
        letsgo(3, 7)));

    // 14번 문제
    if (!which_one_is_big(3, 3))
    {
        printf("대소 비교 불가 == 둘이 숫자 같음\n");
    }

    if ((result = which_one_is_big(3, 7)))
    {
        printf("더 큰 놈은 ? %d\n", result);
    }

    // 15번 문제
    printf("결과 = %d\n", return_integer_from_int_float_parameter(3, 7.7));

    return 0;
}