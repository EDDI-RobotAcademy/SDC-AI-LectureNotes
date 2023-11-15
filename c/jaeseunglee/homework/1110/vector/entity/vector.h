#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct _vector vector;

#define NUMBER_OF_VECTORS       2

#define MIN -9
#define MAX 9

struct _vector
{
    char *name;
    int x;
    int y;
    int z;
    float size;
};

vector *init_vector_object(char *name);
void set_object_vectors(vector *object, int _x, int _y, int _z);
void print_object_vectors(vector *object);
void calculate_vector_size(vector *vector);
void calculate_subjective_vector_A_to_B(vector *vectorA, vector *vectorB);
vector *subjective_vector_A_to_B(vector *A, vector *B);
void set_vectors(vector **vec, char **names);
int random_number();

#endif