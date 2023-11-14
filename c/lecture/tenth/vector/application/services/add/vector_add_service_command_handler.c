#include "vector_add_service_command_handler.h"

#include "../../../adapter/out/in_memory/vector_in_memory_command.h"
#include "../../../adapter/out/in_memory/store/vector_store_in_memory_command_handler.h"
#include "../../../adapter/out/in_memory/vector_in_memory_command_table.h"

#include <stdio.h>

float add_x_request_form(vector_operation_request *request_form)
{
    printf("뭐냐 ? first(x): %5.2f, second(x): %5.2f\n", 
        request_form->first_vector->x, request_form->second_vector->x);
        
    return request_form->first_vector->x + request_form->second_vector->x;
}

float add_y_request_form(vector_operation_request *request_form)
{
    return request_form->first_vector->y + request_form->second_vector->y;
}

float add_z_request_form(vector_operation_request *request_form)
{
    return request_form->first_vector->z + request_form->second_vector->z;
}

void vector_add(vector_operation_request *request_form)
{
    vector_model vector_operation_result;

    printf("벡터 덧셈입니다!\n");
    print_vector_operation_request(request_form);

    init_vector_model_object_with_value(
        &vector_operation_result, 
        add_x_request_form(request_form), 
        add_y_request_form(request_form), 
        add_z_request_form(request_form));

    print_vector_model_object(&vector_operation_result);

    vector_in_memory_command_table[VECTOR_IN_MEMORY_STORE](&vector_operation_result);
}