#include "sample.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH		32

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

// 결론 : malloc을 했으면 free해서 지워라
// malloc - free는 한 쌍
void clear_memory_leak_sample_object(memory_leak_sample* object)
{
	free(object->a_device_message);
	free(object->message);
	
	
	free(object);
}





// request처럼 잠깐 쓰일 객체들은 이런식으로 관리하면됨
void constructor_like_memory_leak_sample(char* message, char* device_message, 
		memory_leak_sample_constructor constructor, memory_leak_sample_destructor destructor)
{
    memory_leak_sample *tmp = constructor();
    
	strncpy(tmp -> message, message, strlen(message)+1);
	strncpy(tmp->a_device_message, device_message, strlen(device_message)+1);

	printf("message: %s\ndevice_message: %s", tmp->message, tmp->a_device_message);

	// 실제로 우리가 Apdater_API_Table에서도
	// request를 생성해서 이와 유사한 구조를 가지고 호출하고 있음

    destructor(tmp);
}

