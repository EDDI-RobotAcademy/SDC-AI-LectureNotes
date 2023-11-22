#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "how_to_write_content.h"

bool write_content_in_file(int file_descriptor, char *content)
{
    int content_length = strlen(content);
    int written_bytes = write(file_descriptor, content, content_length);

    if (written_bytes != content_length)
    {
        printf("write() System Call error!\n");
        return false;
    }

    return true;
}