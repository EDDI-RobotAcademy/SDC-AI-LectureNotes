#include <stdio.h>
#include <stdlib.h>

#include "divisor.h"

void divisor_generation(int number)
{
    printf("%d의 약수는 다음과 같습니다!\n", number);
    
    int divisor;

    for (divisor = 1; divisor <= number; divisor++)
    {
        if ((number % divisor) == 0)
        {
            printf("%3d", divisor);
        }
    }
    
    printf("\n");
}