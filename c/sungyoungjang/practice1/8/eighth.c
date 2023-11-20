#include "eighth.h"

#include "../utility/random.h"
#include "../7/seventh.h"

#include <stdlib.h>

int random_alloc_array(int **array)
{
    int i;
    int random_count = random_gen(5, 10);
    *array = (int *)malloc(sizeof(int) * random_count);

    for (i = 0; i < random_count; i++)
    {
        // 연산자 우선순위 주의:
        // 괄호가 없다면 대괄호가 먼저 연산되므로 이상한 값으로 처리됨
        (*array)[i] = random_gen(1, 10);
    }

    return random_count;
}
