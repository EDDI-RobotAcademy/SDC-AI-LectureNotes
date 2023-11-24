#include "random_size_dynamic_array.h"
#include "../2/random_number_generator.h"
#include <stdlib.h>
#include <stdio.h>

// 1. random size 만큼 input 받아서 sizeof(int) 만큼 만듬
// 2. malloc으로 동적 메모리 할당
// 3.

int get_random_size(void)
{
    int random_size = random_generate(MIN, MAX);

    return random_size;
}

void random_size_dynamic_array(int random_size)
{
    
    int *dynamic_array;
    dynamic_array = (int *)malloc(sizeof(int) * random_size);

    
    for (int i = 0; i <= random_size; i ++){
        dynamic_array[i] = random_generate(MIN, MAX);
        printf("random number:%d\n", dynamic_array[i]);
    }    

}