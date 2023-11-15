#ifndef __VECTOR_OPERATION_REQUEST_H__
#define __VECTOR_OPERATION_REQUEST_H__

#include "../../../../domain/model/vector_model.h"

typedef struct _vector_operation_request vector_operation_request;

struct _vector_operation_request
{
    vector_model *first_vector;
    vector_model *second_vector;
};

vector_operation_request *init_vector_operation_request(vector_model *, vector_model *);
void print_vector_operation_request(vector_operation_request *);

#endif
