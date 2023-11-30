#include <stdio.h>

#include "sample/sample.h"

void alloc_message(char *message)
{

}


int main (void)
{
    // memory_leak_sample *memory_leak_sample = 
    //     init_memory_leak_sample_object();


    // clear_memory_leak_sample_object(memory_leak_sample);

    char message[] = "교수님 뭐라구요?";
    char d_message[] = "아~ 완벽히 이해했어!";

    constructor_like_memory_leak_sample(message, d_message, init_memory_leak_sample_object, clear_memory_leak_sample_object);
    return 0;
}
