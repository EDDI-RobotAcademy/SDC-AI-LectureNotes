#include <stdbool.h>

extern int *integer_dynamic_array;
extern char* char_dynamic_array;

void test_local_variable(void);

void create_int_dynamic_array(int count);
bool put_one_integer_data(int data);
void print_integer_dynamic_array(void);

void create_char_dynamic_array(char* name);
void set_name_to_char_dynamic_array(char* name);
void print_char_dynamic_array(void);
