#include "third.h"
#include "../2/second.h"
#include <stdio.h>


int random_num(void)
{
    
    int random_result = random_gen(1,100);

    if(random_result % 2 == 1)
    {
        printf("%d는 홀수 입니다.\n",random_result);
    }
    
    if(random_result % 2 == 0)
    {
        printf("짝수이므로 출력 X.\n");
    }

    return random_result;

}