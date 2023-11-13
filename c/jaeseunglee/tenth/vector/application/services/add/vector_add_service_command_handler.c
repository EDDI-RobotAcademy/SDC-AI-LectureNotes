#include "vector_add_service_command_handler.h"

#include <stdio.h>

void vector_add(vector_operation_request *request_form)
{
    printf("벡터 덧셈입니다!\n");

    
    print_vector_operation_request(request_form);
}