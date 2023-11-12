#include <stdio.h>
#include <math.h>


#include "vector/vectors.h"
#include "utility/random.h"

#define VECTOR_NUMBER       2
#define FIRST_VECTOR        0
#define SECOND_VECTOR       1

void set_vectors_info(vectors **vectors_object_array, char **name)
{
    int i;
    random_seed_config();
    for(i = 0; i < VECTOR_NUMBER; i++)
    {

        vectors_object_array[i] = init_vectors_object();
        set_vectors_name(vectors_object_array[i], name[i]);
        set_vectors_xyz_number(vectors_object_array[i]);
        print_vectors_object(vectors_object_array[i]);
    }
}

void vector_a_to_b(vectors **vectors_object)
{
    int x,y,z;
    double a_to_b;

    x = vectors_object[FIRST_VECTOR]->x - vectors_object[SECOND_VECTOR]->x;
    y = vectors_object[FIRST_VECTOR]->y - vectors_object[SECOND_VECTOR]->y;
    z = vectors_object[FIRST_VECTOR]->z - vectors_object[SECOND_VECTOR]->z;
    // printf("x = %d, y = %d, z = %d\n",x,y,z);

    a_to_b = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

    printf("%s가 %s를 바라 볼 때 상대 벡터는 = %f\n",vectors_object[FIRST_VECTOR]->vector_name, vectors_object[SECOND_VECTOR]->vector_name, a_to_b);
    

}

int main (void)
{


    vectors *vectors_object[VECTOR_NUMBER];
    char *name[VECTOR_NUMBER] ={
        "A_xyz",
        "B_xyz"
    };

    set_vectors_info(vectors_object, name);
    vector_a_to_b(vectors_object);

    return 0;
}
