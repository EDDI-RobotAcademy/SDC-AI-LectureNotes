
#include "grammar_prob_fourth.h"

void print_start_to_finish(const int start, const int finish)
{
    int i;

    for(i = start; i <= finish; i++)
    {
        printf("number = %2d\n", i);
    }
}