#include <stdio.h>

#include "mutiplication_table.h"

void multiplication_table(void)
{
    printf("구구단을 외자!\n");

    int i, j;

    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            printf("%d X %d = %d\n", i, j, i*j);
        }    
    }
}