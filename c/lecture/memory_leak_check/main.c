#include <stdio.h>

#include "sample/sample.h"



int main (void)
{
	// memory_leak_sample *memory_leak_sample_object =
    //     init_memory_leak_sample_object();

    // clear_memory_leak_sample_object(memory_leak_sample_object);

    char message[] = "이게 되네 ?";
    char device_message[] = "응 다 돼";

    constructor_like_memory_leak_sample(
        message, device_message,
        init_memory_leak_sample_object,
        clear_memory_leak_sample_object
    );

    return 0;
}
