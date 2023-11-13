#include <stdio.h>

#include "vector/application/services/vector_service_command.h"
#include "vector/application/services/add/vector_add_service_command_handler.h"
#include "vector/application/services/sub/vector_sub_service_command_handler.h"
#include "vector/application/services/vector_service_command_table.h"

/*
x, y, z 속도 벡터가 존재합니다.
A_xyz 벡터에 -9 ~ 9 사이의 임의의 크기를 줍니다.
B_xyz 벡터에 -9 ~ 9 사이의 임의의 크기를 줍니다.
통합 벡터는 x, y, z 각각의 벡터의 계산으로 산출합니다.
A가 B를 바라 볼 때 상대 벡터를 출력하세요.
*/

int main (void)
{
    vector_service_command_table[VECTOR_SUB_SERVICE_EXECUTE]();

    return 0;
}
