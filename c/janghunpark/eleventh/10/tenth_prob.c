#include <stdio.h>

#include "tenth_prob.h"

int and_data(int a, int b)
{
    return a & b;
}

int or_data(int a, int b)
{
    return a | b;
}

int xor_data(int a, int b)
{
    return a ^ b ;
}

int not_data(int a)
{
    return ~a;
}