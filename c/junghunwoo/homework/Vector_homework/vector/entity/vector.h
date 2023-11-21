#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct _vector vector;

struct _vector
{
    unsigned int vector_count;
    char *vector_name;
};

vector *init_vector_object(void);
void set_vector_name(vector *object, char *vector_name);
void print_vector_name_object(vector *object);

#endif
