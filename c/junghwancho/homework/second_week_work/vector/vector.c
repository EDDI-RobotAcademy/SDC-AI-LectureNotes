#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vector *init_vector_object(void)
{
    vector *tmp_vector = (vector *)malloc(sizeof(vector));
    return tmp_vector;
}

