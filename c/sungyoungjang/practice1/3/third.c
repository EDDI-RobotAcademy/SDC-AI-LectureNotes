#include "third.h"
#include "../2/second.h"


int random_num(random_gen)
{
    if(random_gen % 2 == 1)
    {
        printf("%d는 홀수 입니다.\n",random_gen);
    }
    
    if(random_gen % 2 == 0)
    {
        printf("짝수이므로 출력 X.\n",random_gen);
    }
}