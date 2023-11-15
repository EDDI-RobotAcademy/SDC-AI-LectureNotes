
#include "vector/entity/vector.h"
#include "utility/random.h"


// 과제
// x y z 벡터가 존재합니다
// A_xyz 벡터에 -9~9 사이의 임의의 크기를 줍니다
// B_xyz 벡터에 -9~9 사이의 임의의 크기를 줍니다.
// 통합 벡터는 x y z 각각의 벡터의 계산으로 산출합니다.
// A가 B를 바라 볼 때 상대 벡터를 출력하세요.
// 통합 벡터 길이 = sqrt(x^2 + y^2 + z^2)






int main (void)
{
    
    random_config();

    vector *vec[NUMBER_OF_VECTORS];
    char *names[NUMBER_OF_VECTORS] = {
        "A벡터",
        "B벡터",
    };

    set_vectors(vec, names);

    print_object_vectors(subjective_vector_A_to_B(vec[0],vec[1]));
     

    return 0;
}

