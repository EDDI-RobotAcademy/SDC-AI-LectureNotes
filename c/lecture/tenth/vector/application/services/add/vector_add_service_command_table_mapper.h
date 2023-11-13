#ifndef __VECTOR_ADD_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __VECTOR_ADD_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "vector_add_service_command.h"
#include "vector_add_service_command_handler.h"

#define __VECTOR_ADD_SERVICE_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__VECTOR_ADD_SERVICE_COMMAND_TABLE(VECTOR_ADD_SERVICE_EXECUTE, vector_add)

#endif