#include "vector.h"

#include <stdio.h>

vector vector_value;

void set_vector_with_domain_model(vector_model *vector_model_object)
{
    vector_value.x = vector_model_object->x;
    vector_value.y = vector_model_object->y;
    vector_value.z = vector_model_object->z;
}

void print_vector(void)
{
    printf("x: %5.2f, y: %5.2f, z: %5.2f\n",
        vector_value.x, vector_value.y, vector_value.z);
}