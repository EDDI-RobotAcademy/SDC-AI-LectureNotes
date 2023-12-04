#include "eighth.h"
#include "../2/second.h"
#include "../7/seventh.h"

#include <stdio.h>
#include <stdlib.h>

int integer_random_array()
{
    int* arr = (int*)malloc(sizeof(int) * COUNT); // 동적 할당

    for (int i = 0; i < COUNT; i++)
    {
        arr[i] = generate_random2(MIN, MAX);
        printf("%5d", arr[i]);
    }

    printf("\n");

    return 0;

}