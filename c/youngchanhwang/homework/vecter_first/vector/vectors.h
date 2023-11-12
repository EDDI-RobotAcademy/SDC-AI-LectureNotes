#ifndef __VECTER_H__
#define __VECTER_H__

typedef struct _vectors vectors;

struct _vectors
{
    char *vector_name;
    int x;
    int y;
    int z;
    
};

#define MAX         9
#define MIN         -9
vectors *init_vectors_object(void);
void set_vectors_name(vectors *object, char *name);
void set_vectors_xyz_number(vectors *object);
void print_vectors_object(vectors *object);



#endif