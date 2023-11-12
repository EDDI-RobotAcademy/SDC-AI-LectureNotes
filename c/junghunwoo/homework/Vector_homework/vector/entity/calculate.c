#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calculate.h"
#include "xyz.h"

/*
caculate init_caculate_object(void)
{
    caculate *tmp_object = (caculate *)malloc(sizeof(caculate));
    return tmp_object;
}
*/
void vector_caculate(caculate *result_object, xyz *object, xyz *target_object)
{
    caculate *result_object = (caculate *)malloc(sizeof(caculate));

    result_object->x_result = object->x_number - target_object->x_number;
    result_object->y_result = object->y_number - target_object->y_number;
    result_object->z_result = object->z_number - target_object->z_number;
    result_object->result = sqrt((result_object->x_result)^2 + (result_object->y_result)^2 + (result_object->z_result)^2);

    
}

void print_vector_caculate(caculate *result_object)
{
    printf("A와 B의 통합 벡터의 길이는 %d이다.\n", result_object->result);
}