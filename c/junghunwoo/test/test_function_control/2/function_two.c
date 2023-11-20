#include "function_two.h"

void number_dvisor(int number)
{
    int i;
    printf("%d의 약수 : ", number);
    
    for (i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            printf("%d, ", i);
        }

    }
    printf("\n");
}