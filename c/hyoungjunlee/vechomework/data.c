#include <stdlib.h>
#include "data.h"
#include "random.h"
#define MIN    -9
#define MAX     9
vec* create_vector(void)
{
    vec* tmp_vector=(vec*)malloc(sizeof(vec));
    
    return tmp_vector;
    
}

void data_input(vec* vector)
{
    vector->x=generate_random_from_min_to_max(MIN,MAX);
    vector->y=generate_random_from_min_to_max(MIN,MAX);
    vector->z=generate_random_from_min_to_max(MIN,MAX);
}




