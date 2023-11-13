#include "vector_random_operation_response.h"

#include "../request/vector_operation_request.h"

#include <stdlib.h>

void vector_random_operation(void)
{
    vector_random_operation_response *request_form;
    int random_command = init_vector_random_operation_response_object(void)
    {
        vector_random_operation_response *response_vector =
            (vector_random_operation_response *)
                malloc(sizeof(vector_random_operation_response));
    
        /* TODO: need to set response value from paramenter*/

        return response_vector;
    }
}
