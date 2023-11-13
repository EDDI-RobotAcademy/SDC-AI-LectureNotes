#ifndef __VECTOR_MODEL_H__
#define __VECTOR_MODEL_H__

#define VECTOR_MIN                 (-9)
#define VECTOR_MAX                 (9)


typedef struct _vector_model vector_model;

struct _vector_model
{
    float x;
    float y;
    float z;
};


vector_model *init_vector_model_object(void);
void print_vector_model_object(vector_model *object);



#endif