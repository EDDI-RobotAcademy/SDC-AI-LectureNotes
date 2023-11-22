#include "board_file_adapter_find_by_id_handler.h"

#include <stdio.h>

#include "../../repository/in_memory_board_manager.h"

in_memory_board *find_by_id_from_file(void *request)
{
    int request_board_id = request;

    printf("Board File Adapter: 특정 게시물 찾기\n");

    return &global_in_memory_board_manager.in_memory_board_array[request_board_id];
}
