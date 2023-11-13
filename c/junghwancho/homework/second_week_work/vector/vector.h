#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct _vector vector;

struct _vector
{
    int x;
    int y;
    int z;
};

vector *init_vector_object(void);


#endif