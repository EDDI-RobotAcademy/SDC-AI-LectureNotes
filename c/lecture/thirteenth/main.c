#include <stdio.h>
#include <fcntl.h>

#include "file_io/how_to_make_file.h"

int main (void)
{
    // 0644는 8진수임
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/lecture/thirteenth/created_file/이거만들래.txt", O_CREAT | O_RDWR, 0644);

    file_close(created_file_descriptor);

    return 0;
}
