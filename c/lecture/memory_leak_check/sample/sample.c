#include "sample.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH			32

memory_leak_sample *init_memory_leak_sample_object(void)
{
	memory_leak_sample *tmp_memory_leak_sample_object =
		(memory_leak_sample *)malloc(sizeof(memory_leak_sample));

	tmp_memory_leak_sample_object->message =
		(char *)malloc(sizeof(char) * MAX_MESSAGE_LENGTH);

	tmp_memory_leak_sample_object->a_device_message =
		(char *)malloc(sizeof(char) * MAX_MESSAGE_LENGTH);

	return tmp_memory_leak_sample_object;
}

// 결론: malloc을 했으면 free 해서 지워라
//      malloc과 free가 한 쌍임
void clear_memory_leak_sample_object(memory_leak_sample *object)
{
	free(object->message);
	free(object->a_device_message);

	free(object);
}

// void constructor_like_memory_leak_sample(
//         memory_leak_sample *(* construct)(void),
//         void (* destruct)(memory_leak_sample *))

/*
typedef memory_leak_sample *(* memory_leak_sample_constructor)(void);

memory_leak_sample_constructor 는
memory_leak_sample * 을 리턴하고
void 를 parameter로 취하는 함수 포인터 타입

typedef void (* memory_leak_sample_destructor)(memory_leak_sample *);

memory_leak_sample_destructor 는
void 를 리턴하고 memory_leak_sample 포인터를 parameter로 취하는 함수 포인터 타입

여기서 타입이란 ? 변수를 작성 할 때 앞에 적는 것
int number에서 int 는 타입입니다.

그러므로 아래와 같이 memory_leak_sample_constructor constructor 로 표현이 가능합니다.
*/

void constructor_like_memory_leak_sample(
		char *message, char *device_message,
        memory_leak_sample_constructor constructor,
        memory_leak_sample_destructor destructor)
{
    memory_leak_sample *memory_leak_sample_object = constructor();

	strncpy(memory_leak_sample_object->message, message, strlen(message) + 1);
	strncpy(memory_leak_sample_object->a_device_message, device_message, strlen(device_message) + 1);

	printf("message: %s\n", memory_leak_sample_object->message);
	printf("device message: %s\n", memory_leak_sample_object->a_device_message);

	// 실제로 우리가 Adapter API Table에서도
	// request를 생성해서 이와 유사한 구조를 가지고 호출하고 있음

    destructor(memory_leak_sample_object);
}
