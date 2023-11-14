#include <stdio.h>

#include "1/func_var_first.h"
#include "2/func_var_second.h"
#include "3/func_var_third.h"
#include "4/func_var_fourth.h"
#include "5/func_var_fifth.h"

#include "6/func_var_sixth.h"
#include "9/func_var_ninth.h"
#include "10/func_var_tenth.h"

int main (void)
{
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

    return 0;
}
