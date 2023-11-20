#ifndef __CALCULATE_H__
#define __CALCULATE_H__

#include "xyz.h"

typedef struct _caculate caculate; 

struct _caculate
{
    int x_result;
    int y_result;
    int z_result;
    int result;
};



caculate init_caculate_object(void);
void vector_caculate(caculate *result_object, xyz *object, xyz *target_object);
void print_vector_caculate(caculate *result_object);


#endif