#include "board_file_adapter_find_all_handler.h"

#include <stdio.h>

#include "../../../../../../file/file.h"
#include "../../repository/in_memory_board_manager.h"

in_memory_board *find_all_from_file(void *domain_board_model)
{
    in_memory_board *in_memory_board_array;

    printf("Board File Adapter: 게시물 전체 찾기\n");

    in_memory_board_array = global_in_memory_board_manager.in_memory_board_array;
    
    return in_memory_board_array;
}