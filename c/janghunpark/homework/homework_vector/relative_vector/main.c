#include <stdio.h>
#include "utility/random/random.h"
#include "vector/entity/vector.h"

int main (void)
{
    // 난수 발생
    random_config();

    // 벡터 A, B 생성
    vector A = generate_random_vector();
    vector B = generate_random_vector();

    // 벡터 A, B 출력
    print_each_vector(A, B);

    // 상대벡터 relative_vector 생성
    vector relative_vector = relative_vector_generation(A, B);

    // 상대벡터 relative_vector 와 벡터 길이 측정 및 출력
    print_relative_vector_and_its_length(relative_vector);

    return 0;
}