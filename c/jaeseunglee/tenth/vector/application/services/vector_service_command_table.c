#include "vector_service_command_table.h"
#include "add/vector_add_service_command_handler.h"
#include "sub/vector_sub_service_command_handler.h"

#include <stdio.h>
#include "vector_service_command.h"

void just_dummy(vector_operation_request *nothing)
{
    printf("단순 더미\n");
}
const vector_service_call_ptr_t \
    vector_service_command_table[VECTOR_SERVICE_EXECUTE_BUFFER_COUNT] = {
        // 배열의 0번부터 ... (숫자) 까지 just_dummy 로 설정함
        [0 ... VECTOR_SERVICE_EXECUTE_BUFFER] = just_dummy,
        // mapper를 선언 한 것 만으로도 mapper가 define한 기능이 동작함
        // 결국 배열의 0번에 vector_add가 들어감
        #include "vector_service_command_table_mapper.h"
};