#include "form_test.h"

#include <stdlib.h>
#include <string.h>

unsigned int test_form_unique_id;

int increment_test_form_unique_id(void)
{
    return test_form_unique_id++;
}

test_form *init_test_form_with_id(int id, char *major, int age, char *self_introduction)
{
    test_form *tmp_form = (test_form *)malloc(sizeof(test_form));
    int major_length = strlen(major) + 1;
    int self_introduction_length = strlen(self_introduction) + 1;

    tmp_form->unique_id = id;
    tmp_form->major = (char *)malloc(sizeof(char) * major_length);
    strncpy(tmp_form->major, major, major_length);

    tmp_form->age = age;
    tmp_form->self_introduction =
        (char *)malloc(sizeof(char) * self_introduction_length);
    strncpy(tmp_form->self_introduction, self_introduction, self_introduction_length);

    return tmp_form;
}

test_form *init_test_form(char *major, int age, char *self_introduction)
{
    test_form *tmp_form = (test_form *)malloc(sizeof(test_form));
    int major_length = strlen(major) + 1;
    int self_introduction_length = strlen(self_introduction) + 1;

    tmp_form->unique_id = increment_test_form_unique_id();
    tmp_form->major = (char *)malloc(sizeof(char) * major_length);
    strncpy(tmp_form->major, major, major_length);

    tmp_form->age = age;
    tmp_form->self_introduction =
        (char *)malloc(sizeof(char) * self_introduction_length);
    strncpy(tmp_form->self_introduction, self_introduction, self_introduction_length);

    return tmp_form;
}

test_form **init_test_form_array(int count)
{
    test_form **tmp_format = (test_form **)malloc(sizeof(test_form *) * count);

    return tmp_format;
}