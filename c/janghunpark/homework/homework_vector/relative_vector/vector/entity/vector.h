#ifndef __VECTOR_H__
#define __VECTOR_H__

#define MIN     -9
#define MAX     9

typedef struct _vector
{
    int x;
    int y;
    int z;
} vector;

vector generate_random_vector(void);
vector relative_vector_generation(vector A, vector B);
void print_each_vector(vector A, vector B);
void print_relative_vector_and_its_length(vector A);

#endif