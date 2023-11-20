#include "vector_sub_service_command_handler.h"

#include <stdio.h>

void vector_sub(vector_operation_request *request_form)
{
    printf("벡터 뺄셈입니다!\n");
    print_vector_operation_request(request_form);
}