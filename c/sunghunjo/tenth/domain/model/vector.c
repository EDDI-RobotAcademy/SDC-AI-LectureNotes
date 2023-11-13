#include "vector.h"
#include "../../utility/random.h"

#include <stdlib.h>
#include <stdio.h>

vector *init_vector_object(void)
{
    vector *tmp_vector = (vector*)malloc(sizeof(vector));
    tmp_vector->x = generate_random(VECTOR_MIN,VECTOR_MAX);
    tmp_vector->y = generate_random(VECTOR_MIN,VECTOR_MAX);
    tmp_vector->z = generate_random(VECTOR_MIN,VECTOR_MAX);

    return tmp_vector;
}

void print_vector_object(vector *object)
{
    printf("x :%f\n",object->x);
    printf("x :%f\n",object->y);
    printf("x :%f\n",object->z);

}