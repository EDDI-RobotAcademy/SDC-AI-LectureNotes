#include "sample.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sample(void)
{
	printf("sample\n");
}

int add_all_start_to_end(int start, int end)
{
	int result = 0;
	for(int i = start; i < end+1; i++)
	{
		result += i;
	}

	return result;
}


for_test_struct *init_for_test_struct_object(char* name, char* phone)
{
	int name_length, phone_length;
	for_test_struct *tmp_struct;

	name_length = strlen(name);
	phone_length = strlen(phone);

	if(name_length == 0) return NULL;

	if(phone_length == 0) return NULL;

	tmp_struct = (for_test_struct *)malloc(sizeof(for_test_struct));

	tmp_struct->name = (char*)malloc(sizeof(char) * name_length +1);
	tmp_struct->phone = (char*)malloc(sizeof(char) * phone_length +1);

	strncpy(tmp_struct->name,name,name_length+1);
	strncpy(tmp_struct->phone,phone,phone_length);

	return tmp_struct;
}

char* get_name(for_test_struct *obj)
{
	return obj->name;
}
char* get_phone(for_test_struct* obj)
{
	return obj->phone;
}

void clear_object(for_test_struct* obj)
{
	free(obj);
}
