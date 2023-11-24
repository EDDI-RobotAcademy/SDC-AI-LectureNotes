#include <stdio.h>

#include "sample/sample.h"

int main (void)
{
	memory_leak_sample *memory_leak_sample_object =
        init_memory_leak_sample_object();

    clear_memory_leak_sample_object(memory_leak_sample_object);

    return 0;
}