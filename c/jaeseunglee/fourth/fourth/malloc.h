#pragma once
#include <stdbool.h>

extern int* integer_dynamic_array;
extern char* char_dynamic_array;

void create_int_dynamic_array(int);
bool put_one_integer_data(int data);
void print_integer_dynamic_array();


void create_char_dynamic_array(char*);
void set_name_to_char_dynamic_array(char* name);
void print_char_dynamic_array();

char* return_string(char* name);