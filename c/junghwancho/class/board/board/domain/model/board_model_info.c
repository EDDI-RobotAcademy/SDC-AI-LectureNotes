#include "board_model_info.h"

#include "board_model_title.h"
#include "board_model_writer.h"
#include "board_model_content.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_every_object_exist(
        board_model_title *board_title,
        board_model_writer *board_writer,
        board_model_content *board_content)
{
    if (board_title == NULL) { return false; }
    if (board_writer == NULL) { return false; }
    if (board_content == NULL) { return false; }

    return true;
}

board_model_info *init_board_model_info_with_parameter(
        board_model_title *board_title,
        board_model_writer *board_writer,
        board_model_content *board_content)
{
    board_model_info *tmp_board_info;

    if (!check_every_object_exist(board_title, board_writer, board_content))
    {
        printf("게시물의 정보가 누락되어 있습니다! 올바른 사용 방식으로 사용해주세요.\n");
        return NULL;
    }

    tmp_board_info =
        (board_model_info *)malloc(sizeof(board_model_info));

    tmp_board_info->board_model_title = board_title;
    tmp_board_info->board_model_writer = board_writer;
    tmp_board_info->board_model_content = board_content;

    return tmp_board_info;
}

board_model_info *update_board_model_info(
        board_model_info *origin, 
        board_model_title *board_title, 
        board_model_content *board_content)
{
    board_model_info *tmp_board_info;
    board_model_writer *tmp_board_writer;

    tmp_board_writer = get_board_model_writer_from_model_info(origin);

    if (!check_every_object_exist(board_title, tmp_board_writer, board_content))
    {
        printf("게시물의 정보가 누락되어 있습니다! 올바른 사용 방식으로 사용해주세요.\n");
        return NULL;
    }

    tmp_board_info =
        (board_model_info *)malloc(sizeof(board_model_info));

    tmp_board_info->board_model_title = board_title;
    tmp_board_info->board_model_writer = tmp_board_writer;
    tmp_board_info->board_model_content = board_content;

    free(origin);

    return tmp_board_info;
}

board_model_writer *get_board_model_writer_from_model_info(board_model_info *object)
{
    return object->board_model_writer;
}

void clear_board_model_info(board_model_info *object)
{
    clear_board_model_title(object->board_model_title);
    clear_board_model_writer(object->board_model_writer);
    clear_board_model_content(object->board_model_content);

    free(object);
}
