#include "seventh.h"
#include "../utility/random.h"
#include "../2/second.h"


void print_array()
{
    random_pick();
    static int array[3] = {0}; //배열 초기화
    int i;

    for(i = 0; i < 3; i++)
    {
        array[i] = random_gen(1,10);
        printf("%3d\n",array[i]);
    }
    
}

