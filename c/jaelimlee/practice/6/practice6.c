// x & ~(2의 y승 - 1)의 의미에 대해 서술하시오.
#include "practice6.h"
#include <math.h>

int square(int x, int y)
{
    return x & ~(int)(pow(2, y) - 1);
}