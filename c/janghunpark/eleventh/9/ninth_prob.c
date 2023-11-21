#include <stdio.h>
#include <stdlib.h>

#include "ninth_prob.h"

char test_overflow(char number)
{
    return ++number;
}

char test_underflow(char number)
{
    return --number;
}