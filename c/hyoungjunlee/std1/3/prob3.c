#include "prob3.h"
#include "../random_set/get_random.h"
#include <time.h>
#include <stdlib.h>
void prob3(void)
{
    random_seed();
    int a=0;
    a = get_random();
    if( a % 2 ==1)
        printf("홀수 -> %d\n",a);
}
//3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.