#include "sample.h"

#include <stdio.h>
#include <stdlib.h>

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
