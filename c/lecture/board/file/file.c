#include "file.h"

#include <stdio.h>
#include <fcntl.h>

#include "raw_io/file_io.h"

void read_file_to_make_board_list(void)
{
    int file_descriptor;
    char read_buffer[BUDDY_PAGE_SIZE] = { 0 };

    printf("파일을 읽어서 게시물 리스트를 생성합니다!\n");

    file_descriptor = file_open("where_am_i.txt", O_RDONLY);
    //printf("file descriptor = %d\n", file_descriptor);

    if (file_descriptor == -1)
    {
        printf("현재 게시판이 텅 비어있습니다!\n");
    }

    //read_from_file
}