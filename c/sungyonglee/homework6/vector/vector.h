#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct _vector vector;

struct _vector
{
    unsigned int id;
    char *name;
    int vector_x;
    int vector_y;
    int vector_z;
};

vector *init_vector_object(void);
void vector_info_allocation(vector **vector_object_array, char **name);
void set_vector_name(vector *object, char *name);
void print_vector_object(vector *object);

#endif