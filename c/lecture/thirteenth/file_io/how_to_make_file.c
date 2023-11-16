#include "how_to_make_file.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int file_open(char *filename, int option, unsigned int permission)
{
    int file_descriptor = open(filename, option, permission);

    if (file_descriptor == ERROR)
    {
        printf("open() System Call error!\n");
        return ERROR;
    }

    return file_descriptor;
}

void file_close(int file_descriptor)
{
    close(file_descriptor);
}