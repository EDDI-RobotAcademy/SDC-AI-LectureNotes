#ifndef _VECTOR_H_
#define _VECTOR_H_

#define MAX_NAME_LENGTH     32
#define MIN_VECTOR_VALUE    -9
#define MAX_VECTOR_VALUE    9

struct _vector
{
    char* name;
    int x;
    int y;
    int z;
    double length;
};

typedef struct _vector vector;

vector* init_vector(char* name);
void free_vector(vector* vec);
void print_vector_info(vector* vec);
void calc_vector(vector* vec1, vector* vec2, vector* result);

#endif