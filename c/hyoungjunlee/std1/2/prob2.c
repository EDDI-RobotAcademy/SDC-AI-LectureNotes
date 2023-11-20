#include "prob2.h"
#include "../random_set/get_random.h"
#include <stdio.h>
#include <time.h>
void prob2(void)
{
    random_seed();
    int a =0;
    a= get_random();
    printf("랜덤 숫자 -> %d\n",a);
}
//2. 랜덤 숫자를 출력하세요.