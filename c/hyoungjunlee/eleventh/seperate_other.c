#include "seperate_other.h"
#include <stdio.h>
void seperate_other(float a)
{
    int b;
    b = (int)a;
    a-=(float)b;
    printf("실수 부분%f \n",a);
}