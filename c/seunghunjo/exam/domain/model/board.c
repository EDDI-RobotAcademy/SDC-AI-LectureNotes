#include "board.h"

#include <stdlib.h>

int id_count;

board *init_board_model_object(void)
{
    board *tmp_board = (board*)malloc(sizeof(board));
    tmp_board->unique_id = id_count++;
    return tmp_board;
}
