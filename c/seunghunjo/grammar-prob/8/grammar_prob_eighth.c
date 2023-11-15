#include "grammar_prob_eighth.h"

#include "../utility/random.h"

#include <stdlib.h>

//                          main_array 지역변수의 주소
int random_alloc_integer_array(int **array)
{
    int i;
    int random_count = generate_random(5,10);
    *array = (int*)malloc(sizeof(int) * random_count);

    for(i =0 ; i < random_count; i++)
    {
        // 연산자 우선순위 주의:
        // 괄호가 없다면 대괄호가 먼저 연산되므로 이상한 값으로 처리
        (*array)[i] = generate_random(1,10);
    }
    return random_count;
}