#include <stdio.h>

#include "vector/entity/vector.h"
#include "vector/entity/xyz.h"
#include "utility/random.h"
#include "vector/entity/calculate.h"

#define MAX_VECTOR_NAME      2
#define MAX_XYZ_COUNT      2
#define CALCULATE   2

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

void xyz_memory_allocation(xyz *xyz_array[MAX_XYZ_COUNT])
{
    int i;

    random_seed_config();

    for (i = 0; i < MAX_XYZ_COUNT; i++)
    {
            xyz_array[i] = init_xyz_object();
            random_xyz(xyz_array[i]);
            print_xyz_object(xyz_array[i]);
    }
}
/*
void vector_caculate_length(caculate *caculate_array[CALCULATE], xyz *object_array[CALCULATE], xyz *target_object_array[CALCULATE])
{
    int i=0;

        vector_caculate(caculate_array[i], object_array[i], target_object_array[i+1]);
        print_vector_caculate(caculate_array[0]);
    
}
*/
int main (void)
{
    vector *vector_name_object[MAX_VECTOR_NAME];
    char *vector_name[MAX_VECTOR_NAME] = {
        "A_Vector",
        "B_Vector"
    };

    xyz *xyz_array[MAX_XYZ_COUNT];


    caculate *caculate_array[CALCULATE];

    vector_name_info_allocation(vector_name_object, vector_name);

    xyz_memory_allocation(xyz_array);

    vector_caculate(caculate_array[0], xyz_array[0], xyz_array[1]);
    
    print_vector_caculate(caculate_array[0]);




    return 0;
}
