#include <stdio.h>
#include <stdlib.h>


#include "xyz.h"
#include "../../utility/random.h"


xyz *init_xyz_object(void)
{
    xyz *tmp_xyz = (xyz *)malloc(sizeof(xyz));
    return tmp_xyz;
};

void random_xyz(xyz *object)
{
    object->x_number =
        generate_random_from_min_to_max(MIN, MAX);
    
    object->y_number =
        generate_random_from_min_to_max(MIN, MAX);
    
    object->z_number =
        generate_random_from_min_to_max(MIN, MAX);
}



void print_xyz_object(xyz *object)
{
    printf("x의 값은 %d\n", object->x_number);
    printf("y의 값은 %d\n", object->y_number);
    printf("z의 값은 %d\n", object->z_number);
}