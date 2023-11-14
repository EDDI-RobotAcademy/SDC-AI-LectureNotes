#include <stdio.h>
#include "practice13.h"

int doit(int num1, int num2)
{
    if (num2 == 0)
    {
        return -1;
    }
    return num1 % num2;
}

int letsgo(int num1, int num2)
{ 
    return num1 + num2;
}