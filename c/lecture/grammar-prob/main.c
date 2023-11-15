#include <stdio.h>

#include "utility/random.h"

#include "1/grammar_prob_first.h"
#include "2/grammar_prob_second.h"
#include "extra/i_wanna_return_float_random.h"

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

    return 0;
}
