#include "board_model.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool check_essential_object_exist(
        board_model_id *board_id,
        board_model_info *board_info)
{
    if (board_id == NULL) { return false; }
    if (board_info == NULL) { return false; }

    return true;
}

board_model *init_board_model_with_parameter(
        board_model_id *board_id, board_model_info *board_info)
{
    board_model *tmp_board;

    if (!check_essential_object_exist(board_id, board_info))
    {
        printf("게시물의 정보가 누락되어 있습니다! 올바른 사용 방식으로 사용해주세요.\n");
        return NULL;
    }

    tmp_board =
        (board_model *)malloc(sizeof(board_model));

    tmp_board->board_model_id = board_id;
    tmp_board->board_model_info = board_info;

    return tmp_board;
}

board_model *create_board_model_with_parameter(
        board_model_info *board_info)
{
    board_model *tmp_board;

    tmp_board = init_board_model_with_parameter(
        init_board_model_id(),
        board_info
    );

    return tmp_board;
}

void clear_board_model(board_model *object)
{
    clear_board_model_id(object->board_model_id);
    clear_board_model_info(object->board_model_info);

    free(object);
}
