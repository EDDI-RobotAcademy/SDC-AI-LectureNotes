#include "vector_math_api_command_table.h"
#include "random_operation/vector_random_operation_math_api_command_handler.h"

#include <stdio.h>
#include "vector_math_api_command.h"

void not_implemented(void)
{
    printf("아직 구현되지 않은 기능입니다!\n");
}

const vector_math_api_call_ptr_t \
    vector_math_api_command_table[VECTOR_MATH_API_CALL_BUFFER_COUNT] = {
        [0 ... VECTOR_MATH_API_CALL_BUFFER] = not_implemented,
        #include "vector_math_api_command_table_mapper.h"
};