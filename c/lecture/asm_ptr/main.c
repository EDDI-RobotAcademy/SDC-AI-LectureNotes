#include <stdio.h>

int main (void)
{
    int i;
    int number = 4;
    int *ptr = &number;
    printf("*ptr = %d\n", *ptr);

    int array[3] = { 1, 2, 3 };
    int *ptr2 = array;
    for (i = 0; i < 3; i++)
    {
        printf("ptr2[%d] = %d\n", i, ptr2[i]);
    }

    int *array2[3] = { &number, &number, &number };
    int **ptr3 = array2;

    for (i = 0; i < 3; i++)
    {
        printf("*ptr3[%d] = %d\n", i, *ptr3[i]);
    }

    return 0;
}