#include "board_model_title.h"

#include "../../../utility/trim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_board_title_validation(char *board_title)
{
    trim_whitespaces(&board_title);

    if (board_title == NULL)
    {
        printf("게시물 제목은 필수입니다!\n");
        return false;
    }

    if (!strncmp(board_title, "\0", 1))
    {
        printf("정상적인 제목을 입력해주세요!\n");
        return false;
    }

    if (strlen(board_title) >= MAX_TITLE_LENGTH)
    {
        printf("게시물 길이는 최대 %d 까지 제한됩니다.\n", MAX_TITLE_LENGTH - 1);
        return false;
    }

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

board_model_title *update_board_model_title(board_model_title *origin, char *board_title)
{
    free(origin);

    return init_board_model_title_with_parameter(board_title);
}

char *get_board_model_title(board_model_title *object)
{
    return object->board_title;
}