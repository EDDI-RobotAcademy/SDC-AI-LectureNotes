#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "vectors.h"
#include "../utility/random.h"

vectors *init_vectors_object(void)
{
    vectors *tmp_vectors = (vectors *)malloc(sizeof(vectors));
    return tmp_vectors;
}

void vector_xyz_number(vectors *object)
{
    object->x = 
        generate_random_from_min_to_max(MIN, MAX);
    object->y = 
        generate_random_from_min_to_max(MIN, MAX);
    object->z = 
        generate_random_from_min_to_max(MIN, MAX);
}