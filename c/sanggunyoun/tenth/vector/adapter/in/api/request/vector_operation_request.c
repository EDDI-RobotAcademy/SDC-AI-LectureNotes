#include "vector_operation_request.h"

#include <stdlib.h>

vector_operation_request *init_vector_operation_request(
    vector_model *first_vector, vector_model *second_vector)
{
    vector_operation_request *vector_request = 
        (vector_operation_request *)
            malloc(sizeof(vector_operation_request));

    vector_request->first_vector = first_vector;
    vector_request->second_vector = second_vector;

    return vector_request;
}

void print_vector_operation_request(vector_operation_request *vector_request)
{
    print_vector_model_object(vector_request->first_vector);
    print_vector_model_object(vector_request->second_vector);
}
