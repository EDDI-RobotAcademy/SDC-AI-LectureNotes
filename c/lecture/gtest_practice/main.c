#include <stdio.h>
#include "simple/add.h"
#include "simple/sub.h"

int main (void)
{
    printf("hi\n");
    printf("add(3, 7) = %d\n", add(3, 7));
    printf("sub(3, 7) = %d\n", sub(3, 7));

    return 0;
}
