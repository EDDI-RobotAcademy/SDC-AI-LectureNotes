#include <stdio.h>

#include "1/func_var_first.h"
#include "2/func_var_second.h"
#include "3/func_var_third.h"
#include "4/func_var_fourth.h"
#include "5/func_var_fifth.h"

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

    return 0;
}
