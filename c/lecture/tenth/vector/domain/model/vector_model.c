#include "vector_model.h"
#include "../../../utility/random.h"

#include <stdlib.h>

vector_model *init_vector_model_object(void)
{
    vector_model *tmp_vector = (vector_model *)malloc(sizeof(vector_model));
    tmp_vector->x = generate_random(VECTOR_MIN, VECTOR_MAX);
    tmp_vector->y = generate_random(VECTOR_MIN, VECTOR_MAX);
    tmp_vector->z = generate_random(VECTOR_MIN, VECTOR_MAX);

    return tmp_vector;
}

void print_vector_model_object(vector_model *object)
{
    printf("x: %f\n", object->x);
    printf("y: %f\n", object->y);
    printf("z: %f\n", object->z);
}
