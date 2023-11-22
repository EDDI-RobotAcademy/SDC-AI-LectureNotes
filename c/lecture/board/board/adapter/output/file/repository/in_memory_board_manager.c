#include "in_memory_board_manager.h"

#include <stdlib.h>

in_memory_board_manager global_in_memory_board_manager;

#define DEFAULT_ALLOC_NUMBER            32

void init_in_memory_board_manager(void)
{
    global_in_memory_board_manager.alloc_count = DEFAULT_ALLOC_NUMBER;
    global_in_memory_board_manager.in_memory_board_array = 
        (in_memory_board *)malloc(sizeof(in_memory_board) * DEFAULT_ALLOC_NUMBER);
}

void alloc_in_memory_board_manager(board_model *board)
{
    int unique_id = get_board_model_id(board->board_model_id);

    alloc_memory_board_object(
        &global_in_memory_board_manager.in_memory_board_array[unique_id],
        unique_id,
        get_board_model_title(board->board_model_info->board_model_title),
        get_board_model_writer(board->board_model_info->board_model_writer),
        get_board_model_content(board->board_model_info->board_model_content)
    );
}