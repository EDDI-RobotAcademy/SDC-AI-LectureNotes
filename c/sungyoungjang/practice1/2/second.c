#include "../utility/random.h"
#include "second.h"

#include <stdio.h>

void random_number(void)
{
    printf("랜덤 숫자는 : %d\n",random_gen(MIN,MAX));
    
}

// 가변
void print_random_number_from_main_parammeter_transfer(const int min,const int max)
{
        printf("(main parameter transfer)랜덤 숫자는 : %d\n",random_gen(min,max));
}
