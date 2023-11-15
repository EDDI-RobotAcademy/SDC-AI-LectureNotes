#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "../../../../domain/model/vector_model.h"

typedef struct _vector vector;

struct _vector
{
    float x;
    float y;
    float z;
};

extern vector vector_value;

void set_vector_with_domain_model(vector_model *vector_model_object);
void print_vector(void);

#endif
