#ifndef __VECTOR_IN_MEMORY_COMMAND_TABLE_MAPPER_H__
#define __VECTOR_IN_MEMORY_COMMAND_TABLE_MAPPER_H__

#include "vector_in_memory_command.h"
#include "store/vector_store_in_memory_cammand_handler.h"

#define __VECTOR_IN_MEMORY_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__VECTOR_IN_MEMORY_COMMAND_TABLE(VECTOR_IN_MEMORY_STORE, store_vector)

#endif