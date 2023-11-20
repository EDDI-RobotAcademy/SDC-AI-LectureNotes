#include "file_io.h"

#include <unistd.h>
#include <string.h>

int file_open(char *filename, int option, unsigned int permission)
{
    int file_descriptor = open(filename, option, permission);

    return file_descriptor;
}

int file_open(char *filename, int option)
{
    int file_descriptor = open(filename, option);

    return file_descriptor;
}

void write_to_file(int file_descriptor, char *write_buffer)
{
    int write_buffer_length = strlen(write_buffer);
    int written_bytes;

    write(file_descriptor, write_buffer, write_buffer_length);

    if (written_bytes != write_buffer_length)
    {
        printf("write() System Call Error!\n");
        exit(-1);
    }
}

void read_from_file(int file_descriptor, char *read_buffer, int size)
{
    int read_bytes;

    read_bytes = read(file_descriptor, read_buffer, size);

    if (read_bytes == -1)
    {
        printf("read() System Call Error!\n");
        exit(-1);
    }
}

void file_close(int file_descriptor)
{
    close(file_descriptor);
}