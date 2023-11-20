#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "vector.h"

unsigned int current_vector_max;

vector *init_vector_object(void)
{
    vector *tmp_vector = (vector *)malloc(sizeof(vector));
    tmp_vector->vector_count  = current_vector_max++;

    return tmp_vector;

}

void set_vector_name(vector *object, char *vector_name)
{
    int name_length = strlen(vector_name) + 1;

    object->vector_name = (char *)malloc(name_length);
    strncpy(object->vector_name, vector_name, name_length);
}

void print_vector_name_object(vector *object)
{
    printf("Vector_count: %d\n", object->vector_count);
    printf("vector_name: %s\n", object->vector_name);
}

