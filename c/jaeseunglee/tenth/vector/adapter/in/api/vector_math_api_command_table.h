#ifndef __VECTOR_MATH_API_COMMAND_TABLE_H__
#define __VECTOR_MATH_API_COMMAND_TABLE_H__

#include "vector_math_api_command.h"
#include "../../../adapter/in/api/request/vector_operation_request.h"


typedef void (* vector_math_api_call_ptr_t) (void);

void not_implemented (void);

extern const vector_math_api_call_ptr_t \
    vector_math_api_command_table[VECTOR_MATH_API_CALL_BUFFER_COUNT];

#endif