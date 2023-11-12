#include <stdio.h>

#include "vector/entity/vector.h"

#define MAX_VECTOR_NAME      2

void vector_name_info_allocation(vector **vector_name_object_array, char **vector_name)
{
    int i;

    for (i = 0; i < MAX_VECTOR_NAME; i++)
    {
        vector_name_object_array[i] = init_vector_object();
        set_vector_name(vector_name_object_array[i], vector_name[i]);
        print_vector_name_object(vector_name_object_array[i]);
    }
}


int main (void)
{
    vector *vector_name_object[MAX_VECTOR_NAME];
    char *vector_name[MAX_VECTOR_NAME] = {
        "A_Vector",
        "B_Vector"
    };

    vector_name_info_allocation(vector_name_object, vector_name);



    return 0;
}
