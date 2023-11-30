#include <stdio.h>
#include <unistd.h>

#include "how_to_read_content.h"

#define BUDDY_PAGE_SIZE     (1)

void read_content_from_file_and_print(int file_descriptor, char* read_content)
{
    int read_bytes;
    
    while((read_bytes = read(file_descriptor,read_content, BUDDY_PAGE_SIZE)) > 0)
    {
        write(1,read_content, read_bytes);
    }
    printf("\n");

}


void read_content_from_file(int file_descriptor, char* read_content)
{
    read(file_descriptor,read_content, 4096);
}


void reset_file_pointer(int file_descriptor)
{
    lseek(file_descriptor,0,SEEK_SET);
}