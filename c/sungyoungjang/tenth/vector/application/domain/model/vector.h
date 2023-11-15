#ifndef __VECTOR_H__
#define __VECTOR_H__

#define VECTOR_MIN (-9)
#define VECTOR_MAX (9)

typedef struct _vector vector;

struct _vector
{
    float x;
    float y;
    float z;
};

#endif