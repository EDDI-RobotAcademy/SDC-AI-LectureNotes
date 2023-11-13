#ifndef __VECTOR_IN_MEMORY_COMMAND_TABLE_H__
#define __VECTOR_IN_MEMORY_COMMAND_TABLE_H__

#include "vector_in_memory_command.h"

void vector_in_memory_not_implemented(void);

typedef void (* vector_in_memory_call_ptr_t) (void);

extern const vector_in_memory_call_ptr_t 
    vector_in_memory_command_table[VECTOR_IN_MEMORY_BUFFER_COUNT];

#endif