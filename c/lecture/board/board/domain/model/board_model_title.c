#include "board_model_title.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_board_title_validation(char *board_title)
{
    if (board_title == NULL)
    {
        printf("게시물 제목은 필수입니다!\n");
        return false;
    }

    // TODO: 공백, 탭 등등 처리 필요함

    return true;
}

board_model_title *init_board_model_title_with_parameter(char *board_title)
{
    int board_title_length;
    board_model_title *tmp_title;

    if (check_board_title_validation(board_title))
    {
        tmp_title = (board_model_title *)malloc(sizeof(board_model_title));
        board_title_length = strlen(board_title);

        strncpy(tmp_title->board_title, board_title, board_title_length);

        return tmp_title;
    }

    return NULL;
}

board_model_title *update_board_model_title(char *board_title)
{
    return NULL;
}