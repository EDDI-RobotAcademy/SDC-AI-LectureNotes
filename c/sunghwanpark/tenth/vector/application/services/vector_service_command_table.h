#ifndef __VECTOR_SERVICE_COMMAND_TABLE_H__
#define __VECTOR_SERVICE_COMMAND_TABLE_H__

#include "vector_service_command.h"

// void (* A) (void) <<< --- 함수 포인터 
// 함수 포인터는 return 타입 입력, parameter 모두 명시해줘야 함 
// 리턴타입 (* 포인터 변수) (parameter) 형태로 작성해야 함 
// 여기 typedef는 void(*)(void) 형태를 vector_service_call_ptr_t로 대체해서 적겠음을 의미함 
typedef void(* vector_service_call_ptr_t)(void);

// 결국 아래는 함수 포인터 배열을 의미함 
extern const vector_service_call_ptr_t
    vector_service_command_table[VECTOR_SERVICE_EXECUTE_BUFFER_COUNT];

#endif