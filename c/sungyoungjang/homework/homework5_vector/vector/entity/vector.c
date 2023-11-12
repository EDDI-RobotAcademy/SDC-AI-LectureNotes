#include <math.h>
#include "vector.h"

int vector_calculate(vector v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}