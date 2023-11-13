#ifndef __VECTOR_ADD_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __VECTOR_ADD_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "vector_service_command.h"
#include "add/vector_add_service_command_handler.h"
#include "sub/vector_sub_service_command_handler.h"

#define __VECTOR_SERVICE_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__VECTOR_SERVICE_COMMAND_TABLE(VECTOR_ADD_SERVICE_EXECUTE, vector_add)
__VECTOR_SERVICE_COMMAND_TABLE(VECTOR_SUB_SERVICE_EXECUTE, vector_sub)

#endif