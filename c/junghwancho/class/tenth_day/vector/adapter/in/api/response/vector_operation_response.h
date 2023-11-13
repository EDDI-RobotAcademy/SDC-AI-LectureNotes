#ifndef __VEECTOR_OPERATION_RESPONSE_H__
#define __VEECTOR_OPERATION_RESPONSE_H__

typedef struct vector_operation_response
    vector_operation_response;

struct vector_operation_response
{
    float x;
    float y;
    float z;
};

vector_operation_response *
    init_vector_operation_response_object(void);

#endif
