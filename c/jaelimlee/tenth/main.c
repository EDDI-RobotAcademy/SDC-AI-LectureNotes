#include <stdio.h>

#include "utility/random.h"

#include "vector/application/services/vector_service_command.h"
#include "vector/application/services/add/vector_add_service_command_handler.h"
#include "vector/application/services/sub/vector_sub_service_command_handler.h"
#include "vector/application/services/vector_service_command_table.h"

#include "vector/adapter/in/api/vector_math_api_command.h"
#include "vector/adapter/in/api/random_operation/vector_random_operation_math_api_command_handler.h"
#include "vector/adapter/in/api/vector_math_api_command_table.h"

int main (void)
{
    coinfig_random_seed();
    
    //vector_service_command_table[VECTOR_SUB_SERVICE_EXECUTE]();
    vector_math_api_command_table[VECTOR_MATH_API_RANDOM_OPERATION]();

    return 0;
}
