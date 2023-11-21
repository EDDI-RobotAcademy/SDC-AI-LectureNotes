#include "file.h"

#include <stdio.h>
#include <fcntl.h>

#include "raw_io/file_io.h"

bool read_file_to_make_board_list(char *read_buffer)
{
    int file_descriptor;

    printf("파일을 읽어서 게시물 리스트를 생성합니다!\n");

    file_descriptor = file_open("../database/board_info.txt", O_RDONLY);

    if (file_descriptor == -1)
    {
        printf("현재 게시판이 텅 비어있습니다!\n");
        return false;
    }

    read_from_file(file_descriptor, read_buffer, BUDDY_PAGE_SIZE);
    file_close(file_descriptor);

    return true;
}
