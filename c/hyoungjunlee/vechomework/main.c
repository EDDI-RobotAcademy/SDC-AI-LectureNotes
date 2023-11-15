#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "data.h"

#include "calculate.h"
#include <time.h>

int main (void)
{
    const int min=-9, max=9;
    vec *a_vec = create_vector();
    vec *b_vec = create_vector();
    random_seed_config();
    data_input(a_vec);
    printf("A 벡터 (%d, %d, %d)\n",a_vec->x,a_vec->y,a_vec->z);
    data_input(b_vec);
    printf("B 벡터 (%d, %d, %d)\n",b_vec->x,b_vec->y,b_vec->z);
    relative_speed(a_vec, b_vec);
    vector_length( a_vec, b_vec);
        
    return 0;
}
