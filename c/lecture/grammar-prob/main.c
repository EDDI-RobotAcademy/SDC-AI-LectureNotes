#include <stdio.h>

#include "utility/random.h"

#include "1/grammar_prob_first.h"
#include "2/grammar_prob_second.h"
#include "extra/i_wanna_return_float_random.h"
#include "3/grammar_prob_third.h"
#include "4/grammar_prob_fourth.h"
#include "5/grammar_prob_fifth.h"
#include "6/grammar_prob_sixth.h"
#include "7/grammar_prob_seventh.h"

int main (void)
{
    int i;
    int *array_pointer;
    config_random_seed();

    // 1 번 문제.
    make_var_after_print();

    // 2 번 문제.
    print_random_number();
    // 2 번 가변 문제.
    print_random_number_from_main_parameter_transfer(3, 4);

    // extra 문제 (랜덤 소수점).
    print_float_random();

    // 3 번 문제.
    print_number_if_even(
        generate_random(7, 10));

    // 3 번 가변 문제.
    print_random_number_and_alloc_to_global(); // <- 3번을 위한 2번 추가 가변
    print_number_if_even(
        get_allocated_global_random_number());

    // 4 번 문제.
    print_start_to_finish(3, 20);

    // 5 번 문제.
    print_integer_from_parameter(7);

    // 6 번 문제.
    printf("6. result = %d\n", return_from_transfer_two_parameter(3, 7));

    // 7 번 문제.
    array_pointer = return_random_array_data();
    printf("7. 배열 받아 출력하기:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%3d", array_pointer[i]);
    }
    printf("\n");

    return 0;
}
