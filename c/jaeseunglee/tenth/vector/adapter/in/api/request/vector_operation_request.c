#include "vector_operation_request.h"

#include <stdlib.h>
#include <stdio.h>

vector_operation_request *init_vector_operation_request(vector_model *first_vector_model, vector_model *second_vector_model)
{
    vector_operation_request *vector_request = (vector_operation_request *)malloc(sizeof(vector_operation_request));

    vector_request->first_vector = first_vector_model;
    vector_request->second_vector = second_vector_model;

    return vector_request;
}


void print_vector_operation_request(vector_operation_request *vector_request)
{
    print_vector_model_object(vector_request->first_vector);
    print_vector_model_object(vector_request->second_vector);
}