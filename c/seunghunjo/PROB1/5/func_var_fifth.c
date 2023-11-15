// shortcut 동작 방식에 대해서 서술해보시오(&&와 ||에 대해서 각각)
#include "func_var_fifth.h"

#include <stdio.h>

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