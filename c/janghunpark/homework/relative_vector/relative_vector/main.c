#include <stdio.h>
#include <math.h>
#include "vector/entity/vector.h"
#include "utility/random/random.h"

/*
< Basic Logic >
1. A[3] = { ax, ay, az }, B[3] = { bx, by, bz }
2. 모든 벡터값을 -9 에서 9 사이 랜덤값으로 도출 (주사위 눈금처럼)
3. printf("sqrt(ax^2 + ay^2 + az^2)" & "sqrt(bx^2 + by^2 + bz^2)");
4. printf("sqrt((ax+bx)^2 + (ay+by)^2) + (az+bz)^2)");
*/

#define NUMBER_OF_VECTORS           2
#define NUMBER_OF_DIRECTIONS        3

#define INDEX_OF_A      0
#define INDEX_OF_B      1

void vector_allocation(vector *vector_array[NUMBER_OF_VECTORS][NUMBER_OF_DIRECTIONS])
{
    int i, j;

    random_seed_config();

    for (i = 0; i < NUMBER_OF_VECTORS; i++)
    {
        for (j = 0; j < NUMBER_OF_DIRECTIONS; j++)
        {
            vector_array[i][j] = init_vector_object();
            set_vector_value(vector_array[i][j]);
            printf("vector[%d][%d] = ", i, j);
            print_vector_value(vector_array[i][j]);
        }
    }
}
/*
void vector_calculation(vector *vector_array[NUMBER_OF_VECTORS][NUMBER_OF_DIRECTIONS])
{

}
*/
int main (void)
{  
    vector *vector_array[NUMBER_OF_VECTORS][NUMBER_OF_DIRECTIONS];
    vector_allocation(vector_array);
    //vector_calculation(vector_array);
    
    return 0;
}