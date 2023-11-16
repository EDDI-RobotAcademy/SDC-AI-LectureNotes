#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "how_to_make_file.h"

int file_open(char *filename, int option, unsigned int permission)
{
    int file_descriptor = open(filename, option);
    printf("file_descriptor = %d\n", file_descriptor);

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