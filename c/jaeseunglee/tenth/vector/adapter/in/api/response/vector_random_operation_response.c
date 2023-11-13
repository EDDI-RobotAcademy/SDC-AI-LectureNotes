#include "vector_random_operation_response.h"

#include <stdlib.h>

vector_random_operation_response *init_vector_random_operation_response_obejct(void)
{
    vector_random_operation_response *response_vector = 
            (vector_random_operation_response *)
                    malloc(sizeof(vector_random_operation_response));

    return response_vector;
}