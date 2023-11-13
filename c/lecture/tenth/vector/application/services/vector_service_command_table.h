#ifndef __VECTOR_SERVICE_COMMAND_TABLE_H__
#define __VECTOR_SERVICE_COMMAND_TABLE_H__

#include "vector_service_command.h"

typedef void (* vector_service_call_ptr_t) (void);

extern const vector_service_call_ptr_t 
    vector_service_command_table[VECTOR_SERVICE_EXECUTE_BUFFER_COUNT];

#endif
