#ifndef __VECTOR_ADD_SERVICE_COMMAND_TABLE_H__
#define __VECTOR_ADD_SERVICE_COMMAND_TABLE_H__

#include "vector_add_service_command.h"

typedef void (* vector_add_service_call_ptr_t) (void);

extern const vector_add_service_call_ptr_t 
    vector_add_service_command_table[VECTOR_ADD_SERVICE_EXECUTE_BUFFER_COUNT];

#endif
