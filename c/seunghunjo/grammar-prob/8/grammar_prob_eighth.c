// 랜덤을 돌려서 임의 개수의 정수형 동적 배열을 만들고 동적 배열에 숫자를 넣은 이후 출력하세요.
#include "grammar_prob_eighth.h"

#include "../utility/random.h"

#include <stdlib.h>

int random_alloc_integer_array(int **array)
{
    int i;
    int random_count = generate_random(5, 10);
    *array = (int *)malloc(sizeof(int) * random_count);

    for (i = 0; i < random_count; i++)
    {
        // 연산자 우선순위 주의:
        // 괄호가 없다면 대괄호가 먼저 연산되므로 이상한 값으로 처리됨
        (*array)[i] = generate_random(1, 10);
    }

    return random_count;
}

int fail_random_alloc_integer_array(int *array)
{
    int i;
    int random_count = generate_random(5, 10);
    array = (int *)malloc(sizeof(int) * random_count);

    for (i = 0; i < random_count; i++)
    {
        // 연산자 우선순위 주의:
        // 괄호가 없다면 대괄호가 먼저 연산되므로 이상한 값으로 처리됨
        array[i] = generate_random(1, 10);
    }

    return random_count;
}