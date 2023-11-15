#include "vector_operation_response.h"

#include <stdlib.h>

vector_operation_response *
    init_vector_operation_response_object(void)
{
    vector_operation_response *response_vector = 
        (vector_operation_response *)
            malloc(sizeof(vector_operation_response));

    /* TODO: need to set response value from parameter */

    return response_vector;
}