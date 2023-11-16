#include <fcntl.h>
#include <unistd.h>

#include "how_to_make_file.h"

int file_open(char *filename,int option, unsigned int permission)
{
    int fd = open(filename, option);

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