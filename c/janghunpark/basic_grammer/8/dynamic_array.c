#include <stdio.h>
#include <stdlib.h>

#include "../random/random.h"
#include "dynamic_array.h"

void generate_and_print_random_int_dynamic_array(void)
{
    int random_array_size = generate_random_number(1, 5);
    int *dynamic_int_array = (int *)malloc(random_array_size * sizeof(int));
    for (int i = 0; i < random_array_size; i++)
    {
        dynamic_int_array[i] = generate_random_number(1, 100);
        printf("dynamic_int_array[%d] = %d\n", i, dynamic_int_array[i]);
    }
}