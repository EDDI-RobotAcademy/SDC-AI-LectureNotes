// 아무런 구조체 대충 하나 만들고 내부에 값을 할당하여 출력해봅시다.
#include "grammar_prob_eleventh.h"

#include "../utility/random.h"

#include <string.h>

test_struct *alloc_test_struct(void)
{
    int i;
    int random_count;
    test_struct *tmp_struct = (test_struct *)malloc(sizeof(test_struct));

    tmp_struct->num1 = 1;
    tmp_struct->num2 = 3.3f;
    tmp_struct->num3 = 7.7;

    random_count = generate_random(3, 6);
    tmp_struct->text = (char *)malloc(sizeof(char) * random_count + 1);

    for (i = 0; i < random_count; i++)
    {
        char character = generate_random(97, 122);
        strncpy(&tmp_struct->text[i], &character, 1);
    }

    return tmp_struct;
}
