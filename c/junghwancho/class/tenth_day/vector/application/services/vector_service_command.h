#ifndef __VECTOR_SERVICE_COMMAND_H__
#define __VECTOR_SERVICE_COMMAND_H__

// enum의 목적은 일단 #define 대용으로 사용
// VECTOR_ADD_SERVICE_EXECUTE는 자동으로 0
// VECTOR_SERVICE_END는 자동으로 1
// 기능을 추가하면 자동으로 숫자 올라가는데
// 밑에 ((VECTOR_SERVICE_END) -1)을 통해 SERVICE END 전까지 사용하겠다.
enum vector_service_command
{
    VECTOR_ADD_SERVICE_EXECUTE,
    VECTOR_SUB_SERVICE_EXECUTE,
    VECTOR_SERVICE_END
};

// 위에 정의된 순서대로 기능이 작동되며, VECTOR_SERVICE_END -1 의 의미는 그 이전의 기능까지 사용하겠다.
#define VECTOR_SERVICE_EXECUTE_BUFFER_COUNT         (VECTOR_SERVICE_END)
#define VECTOR_SERVICE_EXECUTE_BUFFER               ((VECTOR_SERVICE_END) - 1)

#endif