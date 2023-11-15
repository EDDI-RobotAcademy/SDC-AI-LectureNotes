#include "mul.h"
#include <stdio.h>

double mul_double_int(double a, int b)
{
    return a*b;
}

void print_mul_double_int(double a, int b, double result)
{
    printf("%f * %d = %f\n",a,b,result);
}