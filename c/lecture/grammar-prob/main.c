#include <stdio.h>

#include "utility/random.h"

#include "1/grammar_prob_first.h"
#include "2/grammar_prob_second.h"

int main (void)
{
    config_random_seed();

    make_var_after_print();
    print_random_number();

    return 0;
}
