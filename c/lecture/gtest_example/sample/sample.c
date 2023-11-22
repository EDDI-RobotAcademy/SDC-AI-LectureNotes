#include "sample.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add_all_to_end_from_start(int start, int end)
{
	int i;
	int sum = 0;

	for (i = start; i <= end; i++)
	{
		sum += i;
	}

	return sum;
}

for_test_struct *init_for_test_struct_object(char *name, char *phone)
{
	int name_length, phone_length;
	for_test_struct *tmp_test_struct;
	
	name_length = strlen(name);
	phone_length = strlen(phone);

	if (name_length == 0) { return NULL; }

	if (phone_length == 0) { return NULL; }

	tmp_test_struct = (for_test_struct *)malloc(sizeof(for_test_struct));

	// ? 왜 터졌지 ? 메모리 할당 안해서
	tmp_test_struct->name = (char *)malloc(sizeof(char) * name_length + 1);
	tmp_test_struct->phone = (char *)malloc(sizeof(char) * phone_length + 1);
	// ? 왜 터졌지 ? 메모리 할당 안해서

	// strncpy를 strncmp로 작성하는 실수 <- test로 찾고 고칠 수 있음
	strncpy(tmp_test_struct->name, name, name_length + 1);
	strncpy(tmp_test_struct->phone, phone, phone_length + 1);

	return tmp_test_struct;
}

char *get_for_test_struct_name(for_test_struct *object)
{
	return object->name;
}

char *get_for_test_struct_phone(for_test_struct *object)
{
	return object->phone;
}

void clear_for_test_struct_object(for_test_struct *origin)
{
	free(origin);
}