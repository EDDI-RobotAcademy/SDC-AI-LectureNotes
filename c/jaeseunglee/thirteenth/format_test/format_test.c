#include <stdlib.h>
#include <string.h>

#include "format_test.h"

unsigned int test_form_unique_id = 0 ;

int increment_test_form_unique_id(void)
{
    return test_form_unique_id++;
}

test_form *init_test_form(char *major, int age, char *self_introduction)
{
    test_form *tmp_test_form = (test_form *)malloc(sizeof(test_form));
    int major_length = sizeof(major) +1;
    int introduction_length = sizeof(self_introduction) +1;

    tmp_test_form->unique_id = increment_test_form_unique_id();

    tmp_test_form->major = (char *)malloc(major_length);
    strcpy(tmp_test_form->major, major);

    tmp_test_form->age = age;

    tmp_test_form->self_introduction = 
        (char *)malloc(introduction_length);
    strcpy(tmp_test_form->self_introduction, self_introduction);
    
    return tmp_test_form;
}

test_form **init_test_form_array(int count)
{
    test_form **tmp_format = (test_form **)malloc(sizeof(test_form *) * count);
    return tmp_format;
}