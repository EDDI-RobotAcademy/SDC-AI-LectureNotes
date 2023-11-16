#include "how_to_make_file.h"

#include <unistd.h>

int file_open(char *filename, int option, unsigned int permission)
{
    int fd = open(filename, option, permission);

    if (fd == ERROR)
    {
        printf("open() System Call error!\n");
        return ERROR;
    }
}

void file_close(int file_descriptor)
{
    close(file_descriptor);
}