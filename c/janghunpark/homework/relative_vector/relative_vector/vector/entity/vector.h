#ifndef __VECTOR_H__
#define __VECTOR_H__

#define MIN     -9
#define MAX     9

typedef struct _vector vector;

struct _vector
{
    int vector_value;
};

vector *init_vector_object(void);
void set_vector_value(vector *number);
void get_vector_value(vector *number);
void print_vector_value(vector *number);

#endif