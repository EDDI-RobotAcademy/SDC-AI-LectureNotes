#include "file_io.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

    written_bytes = write(file_descriptor, write_buffer, write_buffer_length);

    if (written_bytes != write_buffer_length)
    {
        printf("write_buffer_length = %d, written_bytes = %d\n", 
                    write_buffer_length, write_buffer_length);
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

void reset_file_pointer(int file_descriptor)
{
    lseek(file_descriptor, 0, SEEK_SET);
}

int file_total_length (int file_descriptor)
{
    return lseek(file_descriptor, 0, SEEK_END);
}

void move_file_pointer(int file_descriptor, int point)
{
    lseek(file_descriptor, point, SEEK_SET);
}

void file_close(int file_descriptor)
{
    close(file_descriptor);
}