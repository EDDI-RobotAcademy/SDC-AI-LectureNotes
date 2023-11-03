#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "malloc.h"


int* integer_dynamic_array;
int current_integer_dynamic_array_index;

char* char_dynamic_array;
int current_char_dynamic_array_index;


void creat_char_dynamic_array(char* name)
{
	char_dynamic_array = (char*)malloc(sizeof(char) * (strlen(name) + 1));
}

void set_name_to_char_dynamic_array(char* name)
{
	strncpy(char_dynamic_array, name, strlen(name) + 1);
}

void creat_int_dynamic_array(int count);
bool put_one_integer_data(int data);
void print_integer_dynamic_array(void);