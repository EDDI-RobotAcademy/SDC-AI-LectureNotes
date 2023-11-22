#include "nineth.h"

#include "../utility/random.h"

int malloc_array(int *count)
{
    int i;
    int *tmp_array;

    *count = random_gen(1,10);

    *tmp_array = (int *)malloc(sizeof(int) * (*count));

    for(i = 0;i < *count; i++)
    {
        tmp_array[i] = random_gen(5,10);
    }

    return tmp_array;
}