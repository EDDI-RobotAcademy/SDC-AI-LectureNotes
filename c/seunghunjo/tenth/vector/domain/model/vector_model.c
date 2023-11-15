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

// TODO: 실제로는 #define을 사용해서 함수 오버로딩을 했어야함
vector_model *init_vector_model_object_with_vector(vector_model *vector_object)
{
    vector_model * tmp_vector = (vector_model*)malloc(sizeof(vector_model));

    tmp_vector->x = vector_object->x;
    tmp_vector->y = vector_object->y;
    tmp_vector->z = vector_object->z;

    return tmp_vector;
}

void init_vector_model_object_with_value(
    vector_model *vector_object, float x, float y, float z)
{
    vector_object->x = x;
    vector_object->y = y;
    vector_object->z = z;
}

void print_vector_model_object(vector_model *object)
{
    printf("\{ x: %5.2f, y: %5.2f, z: %5.2f \}\n", object->x, object->y, object->z);
}