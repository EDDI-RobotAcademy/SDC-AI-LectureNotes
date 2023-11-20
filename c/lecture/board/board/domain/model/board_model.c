#include "board_model.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

board_model *init_board_model_with_parameter(
        board_model_id *id, board_model_title *title,
        board_model_writer *writer, board_model_content *content)
{

}

void clear_board_model(board_model *object)
{
    free(object);
}
