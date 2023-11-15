#include "vector_in_memory_command_table.h"
#include "store/vector_store_in_memory_cammand_handler.h"

#include <stdio.h>
#include "vector_in_memory_command.h"

#include "../../../domain/model/vector_model.h"

void vector_in_memory_not_implemented(vector_model *vector_object)
{
    printf("아직 기능이 구현되지 않았습니다!\n");
}

const vector_in_memory_call_ptr_t \
    vector_in_memory_command_table[VECTOR_IN_MEMORY_BUFFER_COUNT] = {
        [0 ... VECTOR_IN_MEMORY_BUFFER] = vector_in_memory_not_implemented,
        #include "vector_in_memory_command_table_mapper.h"
};