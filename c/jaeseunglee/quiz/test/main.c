#include <stdio.h>
#include <stdlib.h>

#include "random/random.h"
#include "quiz/quiz.h"
#include "quiz2/quiz2.h"


void int_array_print(int *number)
{
    int i;
    int result = *number / sizeof(int);
    for(i = 0; i < result ; i++)
    {
        printf("정수형 배열 출력: %d\n",number[i]);
    }
}

int aa(float a)
{
    return a;
}

int main (void)
{
   



    random_config();

    


    quiz1(random_float(),random_int());

    quiz2(random_int(),random_int());

    quiz3_int(random_float());
    quiz3_float(random_float());

    quiz4();
    quiz5();
    quiz6(random_int(),random_int());
    quiz7();
    quiz8();
    quiz9();
    quiz10();
    quiz11();
    
    quiz13(random_int(),random_int());
    quiz14(random_int(), random_int());
    quiz15(3,7.7f);
    

    quiz2_1();
    quiz2_2();
    quiz2_3();
    quiz2_4();
    quiz2_5(random_int());
    quiz2_6(random_int(),random_int());
    quiz2_7();
    quiz2_8();
    quiz2_9();
    quiz2_10();
    quiz2_11();
    quiz2_12();

    

    return 0;
}
