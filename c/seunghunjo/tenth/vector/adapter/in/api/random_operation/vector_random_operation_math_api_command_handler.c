#include "vector_random_operation_math_api_command_handler.h"

#include "../../../../domain/model/vector_model.h"
#include "../../../../../utility/random.h"

#include "../../../../application/services/vector_service_command.h"
#include "../../../../application/services/add/vector_add_service_command_handler.h"
#include "../../../../application/services/sub/vector_sub_service_command_handler.h"
#include "../../../../application/services/vector_service_command_table.h"

#include "../request/vector_operation_request.h"

#include <stdio.h>

void vector_random_operation(void)
{
    vector_operation_request *request_vector_form;
    int random_command = generate_random(VECTOR_ADD_SERVICE_EXECUTE, 
                                            VECTOR_SUB_SERVICE_EXECUTE);
                                            
    vector_model *A_vector = init_vector_model_object();
    vector_model *B_vector = init_vector_model_object();

    request_vector_form = init_vector_operation_request(A_vector, B_vector);
    //print_vector_operation_request(request_vector_form);

    printf("벡터 랜덤 연산을 수행합니다!\n");

    vector_service_command_table[random_command](request_vector_form);
}