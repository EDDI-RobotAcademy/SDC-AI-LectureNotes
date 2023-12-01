#ifndef __FORMAT_TEST_H__
#define __FORMAT_TEST_H__

extern unsigned int test_form_unique_id;

typedef struct _test_form test_form;

struct _test_form
{
    int unique_id;
    char *major;
    int age;
    char *self_introduction;
};

int increment_test_form_unique_id(void);
test_form *init_test_form(char *, int, char *);
test_form **init_test_form_array(int count);

#endif