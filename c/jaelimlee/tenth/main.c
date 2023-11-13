#include <stdio.h>

#include "vector/application/services/vector_service_command.h"
#include "vector/application/services/add/vector_add_service_command_handler.h"
#include "vector/application/services/sub/vector_sub_service_command_handler.h"
#include "vector/application/services/vector_service_command_table.h"

int main (void)
{
    vector_service_command_table[VECTOR_SUB_SERVICE_EXECUTE]();

    return 0;
}
