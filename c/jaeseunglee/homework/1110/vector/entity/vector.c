#include "vector.h"
#include "../../utility/random.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


vector *init_vector_object(char *name)
{
    vector *tmp_vector = (vector *)malloc(sizeof(vector));
    tmp_vector->name = name;
    return tmp_vector;
}

void set_object_vectors(vector *object, int _x, int _y, int _z)
{
    object->x = _x;
    object->y = _y;
    object->z = _z;
    calculate_vector_size(object);
}

void print_object_vectors(vector *object)
{
    printf("벡터 이름: %s\nx: %d\ny: %d\nz: %d\nsize: %f\n\n", object->name, object->x, object->y, object->z, object->size);
}


int random_number()
{
    return generate_random_from_min_to_max(MIN,MAX);
}

void set_vectors(vector **vec, char **names)
{
   int init_loop = NUMBER_OF_VECTORS;

    for(init_loop = 0; init_loop < NUMBER_OF_VECTORS; init_loop ++)
    {
        vec[init_loop] = init_vector_object(names[init_loop]);

        set_object_vectors(vec[init_loop],
            random_number(), random_number(), random_number());
        
        print_object_vectors(vec[init_loop]);
    }
}



vector *subjective_vector_A_to_B(vector *vectorA, vector *vectorB)
{
    char *name = "상대 벡터";
    vector *tmp_vector = init_vector_object(name);
    
    
    
    int tmp_x = vectorA->x - vectorB->x;
    int tmp_y = vectorA->y - vectorB->y;
    int tmp_z = vectorA->z - vectorB->z;
    set_object_vectors(tmp_vector, tmp_x, tmp_y, tmp_z);
    return tmp_vector;
}

void calculate_vector_size(vector *vector)
{
    vector->size = sqrt(pow(vector->x,2)+pow(vector->y,2)+pow(vector->z,2));
}


void calculate_subjective_vector_A_to_B(vector *vectorA, vector *vectorB)
{
    vector *tmp_vector = (vector *)malloc(sizeof(vector));
    int tmp_x = vectorA->x - vectorB->x;
    int tmp_y = vectorA->y - vectorB->y;
    int tmp_z = vectorA->z - vectorB->z;
    set_object_vectors(tmp_vector, tmp_x, tmp_y, tmp_z);
    
}
