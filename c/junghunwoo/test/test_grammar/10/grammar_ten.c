
#include "grammar_ten.h"


#define ARRAY_MAX       10

int add_every_array_element(void)
{
    int i;
    int sum = 0;
    int tmp_array[ARRAY_MAX] = { 0 };

    for (i = 0; i < ARRAY_MAX; i++)
    {
        tmp_array[i] = generate_random(3, 7);
        sum += tmp_array[i]

    }

    return tmp_array;
}