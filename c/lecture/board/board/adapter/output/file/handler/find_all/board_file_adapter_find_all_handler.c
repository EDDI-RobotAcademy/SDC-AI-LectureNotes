#include "board_file_adapter_find_all_handler.h"

#include <stdio.h>

#include "../../../../../../file/file.h"
#include "../../../../../../in_memory/board/in_memory_board_manager.h"

// 1. Enter 개수를 찾는다.
// 2. 실제 구조체를 생성할 때 몇 개의 필드가 필요한지 파악한다.
in_memory_board **transform_read_buffer_to_board_list(char *buffer)
{
    return NULL;
}

in_memory_board **find_all_from_file(void)
{
    bool can_read_file;
    char read_buffer[BUDDY_PAGE_SIZE] = { 0 };

    printf("Board File Adapter: 게시물 전체 찾기\n");

    can_read_file = read_file_to_make_board_list(read_buffer);

    if (!can_read_file) { return NULL; }

    return transform_read_buffer_to_board_list(read_buffer);;
}