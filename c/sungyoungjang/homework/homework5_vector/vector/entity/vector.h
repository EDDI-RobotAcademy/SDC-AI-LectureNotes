#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct _vector vector;
struct vector
{
    int x;
    int y;
    int z;
};

int vector_calculate(vector v);

#endif
