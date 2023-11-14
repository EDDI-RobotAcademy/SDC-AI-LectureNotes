#include <stdio.h>
#include "1/first.h"
#include "2/second.h"
#include "4/fourth.h"
#include "5/fifth.h"

int main (void)
{
    // 1번 문제
first_func();

    // 2, 3번 문제
config_random_seed();
random_number();

    // 4번 문제
print_number_three_to_twenty();

    // 5번 문제
print_parameter(7);

    return 0;
}
