#include "vector_add_service_command_table.h"
#include "vector_add_service_command_handler.h"

#include <stdio.h>
#include "vector_add_service_command.h"

void just_dummy(void)
{
    printf("단순 더미\n");
}

const vector_add_service_call_ptr_t \
    vector_add_service_command_table[VECTOR_ADD_SERVICE_EXECUTE_BUFFER_COUNT] = {
        [0 ... VECTOR_ADD_SERVICE_EXECUTE_BUFFER] = just_dummy,
        #include "vector_add_service_command_table_mapper.h"
};