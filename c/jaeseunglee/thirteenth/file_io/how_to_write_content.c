#include "how_to_write_content.h"

#include <string.h>
#include <unistd.h>
#include <printf.h>

bool write_content_in_file(int file_descriptor, char *content)
{
    int content_length = strlen(content);
    int written_bytes = write(file_descriptor, content, content_length);

    if(written_bytes != content_length)
    {
        printf("write() System Call ERROR!\n");
        return false;
    }

    return true;
}