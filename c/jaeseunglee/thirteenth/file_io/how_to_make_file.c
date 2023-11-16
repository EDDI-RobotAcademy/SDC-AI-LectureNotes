#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include "how_to_make_file.h"


int file_open(char *filename, int option, unsigned int permission)
{
    int fd = open(filename, option, permission);

    if(fd == ERROR)
    {
        printf("open() System Call Error!\n");
        return ERROR;
    }
    return fd;
}

void file_close(int file_descriptor)
{
    close(file_descriptor);
}
