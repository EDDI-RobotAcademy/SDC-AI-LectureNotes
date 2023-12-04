#include "practice14.h"
#include <stdio.h>

int distinction(int a, int b)
{
    if (a > b)
    {
        printf("a: %d, b: %d, a가 b보다 큼\n", a, b);
    }

    else if (a < b)
    {
        printf("a: %d, b: %d, b가 a보다 큼\n", a, b);
    }

    else if (a == b)
    {
        printf("a: %d, b: %d, a와 b는 같음\n", a, b);
    }
}