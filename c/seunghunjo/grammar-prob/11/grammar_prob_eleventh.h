#ifndef __GRAMMAR_PROB_ELEVENTH_H__
#define __GRAMMAR_PROB_ELEVENTH_H__

typedef struct _test_struct test_struct;

struct _test_struct
{
    int num1;
    float num2;
    double num3;
    char *text;
};

test_struct *alloc_test_struct(void);

#endif