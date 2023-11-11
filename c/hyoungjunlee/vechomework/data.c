#include <stdlib.h>
#include "data.h"
vec* create_vector(void)
{
    vec* tmp_vector=(vec*)malloc(sizeof(vec));
    tmp_vector->x=88;
    return tmp_vector;
    
}

