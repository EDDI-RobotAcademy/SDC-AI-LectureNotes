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
        // 0번 배열부터 ... VECTOR_SERVICE_EXECUTE_BUFFER 까지 just_dummy로 설정 = NULL로 해도 관계 없음, 문법 상 무언가 들어가야함
        [0 ... VECTOR_SERVICE_EXECUTE_BUFFER] = just_dummy,
        #include "vector_service_command_table_mapper.h" // 그걸 다시 maaper에 정의된 명령(vector_add)로 설정
};