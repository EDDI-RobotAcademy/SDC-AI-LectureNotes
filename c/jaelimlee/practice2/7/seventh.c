#include "seventh.h"
#include "../2/second.h"
#include <stdio.h>


int integer_array()
{
    int array[COUNT]; // 배열 생성

    config_random_seed(); // 난수 초기화 

    for (int i = 0; i < COUNT; i++)
    {
        array[i] = generate_random2(MIN, MAX); // 난수 배열에 추가
        printf("%5d", array[i]);
    }
    printf("\n");

    return 0;
}

