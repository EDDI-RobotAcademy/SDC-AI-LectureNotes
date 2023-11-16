#ifndef __VECTOR_MATH_API_COMMAND_TABLE_MAPPER_H__
#define __VECTOR_MATH_API_COMMAND_TABLE_MAPPER_H__

#include "vector_math_api_command.h"
#include "random_operation/vector_random_operation_math_api_command_handler.h"

#define __VECTOR_MATH_API_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__VECTOR_MATH_API_COMMAND_TABLE(VECTOR_MATH_API_RANDOM_OPERATION, vector_random_operation)

#endif