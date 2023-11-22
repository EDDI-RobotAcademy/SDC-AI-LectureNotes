#include "tenth.h"

#include "../utility/random.h"

#include <stdio.h>

#define ARRAY_MAX             10

int add_every_array_element(void)
{
    int i;
    int sum = 0;
    int tmp_array[ARRAY_MAX] = { 0 };

    for (i = 0; i < ARRAY_MAX; i++)
    {
        tmp_array[i] = random_gen(3, 7);
        printf("임시 배열 요소 = %d\n", tmp_array[i]);
        sum += tmp_array[i];
    }

    return sum;
}