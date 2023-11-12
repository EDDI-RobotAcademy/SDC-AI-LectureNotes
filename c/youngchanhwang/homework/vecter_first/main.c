#include <stdio.h>


#include "vector/vectors.h"
#include "utility/random.h"

#define VECTOR_NUMBER       2


int main (void)
{
    int i;

    vectors *vectors_object[VECTOR_NUMBER];
    char *name[VECTOR_NUMBER] ={
        "A_xyz",
        "B_xyz"
    };

    random_seed_config();
    for(i = 0; i <VECTOR_NUMBER; i++)
    {

        vectors_object[i] = init_vectors_object();
        set_vectors_name(vectors_object[i], name[i]);
        set_vectors_xyz_number(vectors_object[i]);
        print_vectors_object(vectors_object[i]);
    }



    return 0;
}
