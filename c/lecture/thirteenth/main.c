#include <stdio.h>
#include <fcntl.h>

#include "file_io/how_to_make_file.h"
#include "file_io/how_to_write_content.h"

#define TEST_LENGTH         32

int main (void)
{
    short test_number = 32768;
    char contents[TEST_LENGTH] = "마 좀 치나 ?";

    // 0644는 8진수임
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/lecture/thirteenth/created_file/이거만들래.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    printf("생성된 파일 디스크립터: %d\n", created_file_descriptor);
    printf("short test = %d\n", test_number);

    write_content_in_file(created_file_descriptor, contents);

    file_close(created_file_descriptor);

    return 0;
}
