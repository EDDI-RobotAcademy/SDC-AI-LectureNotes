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

void set_vectors_name(vectors *object, char *name)
{
    int name_length = strlen(name) + 1;

    object->vector_name = (char *)malloc(sizeof(char) * name_length);
    strncpy(object->vector_name, name, name_length);
}

void set_vectors_xyz_number(vectors *object)
{
    object->x = 
        generate_random_from_min_to_max(MIN, MAX);
    object->y = 
        generate_random_from_min_to_max(MIN, MAX);
    object->z = 
        generate_random_from_min_to_max(MIN, MAX);
}

void print_vectors_object(vectors *object)
{
    printf("vectors name: %s\n", object->vector_name);
    printf("x: %d\n", object->x);
    printf("y: %d\n", object->y);
    printf("z: %d\n", object->z);
}
