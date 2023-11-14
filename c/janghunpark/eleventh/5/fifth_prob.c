#include <stdio.h>

#include "fifth_prob.h"

int shortcut_test(int number)
{
    int tmp_number = number;

    if (tmp_number > 10 && tmp_number++ < 20)
    {
        printf("\t> 10 && < 20 tmp_number = %d\n", tmp_number);
    }

    if (tmp_number < 10 || tmp_number-- > 1)
    {
        printf("\t< 10 || > 1 tmp_number = %d\n", tmp_number);
    }

    return tmp_number;
}