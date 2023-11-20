#include "board_file_adapter_handler.h"

#include <stdio.h>

#include "../../../../../file/file.h"

void find_all_from_file(void)
{
    printf("Board File Adapter: 게시물 조회\n");

    read_file_to_make_board_list();
}