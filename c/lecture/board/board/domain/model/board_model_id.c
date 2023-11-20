#include "board_model_id.h"

#include <stdlib.h>

unsigned int board_id_unique_number;

board_model_id *init_board_model_id(void)
{
    board_model_id *tmp_id = (board_model_id *)malloc(sizeof(board_model_id));
    tmp_id->board_id = increment_board_id_unique_number();
    
    return tmp_id;
}

board_model_id *init_board_model_id_with_parameter(unsigned int board_id)
{
    board_model_id *tmp_id = (board_model_id *)malloc(sizeof(board_model_id));
    tmp_id->board_id = board_id;

    return tmp_id;
}

unsigned int get_board_model_id(board_model_id *object)
{
    return object->board_id;
}

unsigned int increment_board_id_unique_number(void)
{
    return board_id_unique_number++;
}

void clear_board_model_id(board_model_id *object)
{
    free(object);
}