#include <math.h>
#include <stdio.h>
#include "vector.h"
#include "../generator/random_generator.h"

vector* init_vector(char* name)
{
    vector* tmp_vector;
    tmp_vector = (vector*)malloc(sizeof(vector));

    tmp_vector->name = (char*)malloc(MAX_NAME_LENGTH);
    strncpy(tmp_vector->name, name, strlen(name));

    tmp_vector->x = generate_random(MIN_VECTOR_VALUE, MAX_VECTOR_VALUE);
    tmp_vector->y = generate_random(MIN_VECTOR_VALUE, MAX_VECTOR_VALUE);
    tmp_vector->z = generate_random(MIN_VECTOR_VALUE, MAX_VECTOR_VALUE);

    tmp_vector->length = (double)sqrt((tmp_vector->x) * (tmp_vector->x) + (tmp_vector->y) * (tmp_vector->y) + (tmp_vector->z) * (tmp_vector->z));

    return tmp_vector;
}

void free_vector(vector* vec)
{
    free(vec->name);
    free(vec);
}

void print_vector_info(vector* vec)
{
    printf("벡터 %s의 x성분: %d, y성분: %d, z성분: %d 길이: %f\n", vec->name, vec->x, vec->y, vec->z, vec->length);
}

void calc_vector(vector* vec1, vector* vec2, vector* result)
{
    result->x = vec1->x - vec2->x;
    result->y = vec1->y - vec2->y;
    result->z = vec1->z - vec2->z;

    result->length = (double)sqrt((result->x) * (result->x) + (result->y) * (result->y) + (result->z) * (result->z));
}