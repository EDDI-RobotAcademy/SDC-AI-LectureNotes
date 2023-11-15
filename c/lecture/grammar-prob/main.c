#include <stdio.h>

#include "utility/random.h"

#include "1/grammar_prob_first.h"
#include "2/grammar_prob_second.h"
#include "extra/i_wanna_return_float_random.h"
#include "3/grammar_prob_third.h"

int main (void)
{
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

    return 0;
}
