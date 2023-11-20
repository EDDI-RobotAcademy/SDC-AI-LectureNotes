#include "board_model_content.h"

#include "../../../utility/trim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_board_content_validation(char *board_content)
{
    trim_whitespaces(&board_content);

    if (board_content == NULL)
    {
        printf("게시물 내용을 작성해주세요!\n");
        return false;
    }

    if (!strncmp(board_content, "\0", 1))
    {
        printf("정상적인 내용을 입력해주세요!\n");
        return false;
    }

    if (strlen(board_content) >= MAX_CONTENT_LENGTH)
    {
        printf("게시물 내용은 최대 %d 까지 제한됩니다.\n", MAX_CONTENT_LENGTH - 1);
        return false;
    }

    return true;
}

board_model_content *init_board_model_content_with_parameter(char *board_content)
{
    int board_content_length;
    board_model_content *tmp_content;

    if (check_board_content_validation(board_content))
    {
        tmp_content = (board_model_content *)malloc(sizeof(board_model_content));
        board_content_length = strlen(board_content);

        strncpy(tmp_content->board_content, board_content, board_content_length);

        return tmp_content;
    }

    return NULL;
}

board_model_content *update_board_model_content(board_model_content *origin, char *board_content)
{
    free(origin);

    return init_board_model_content_with_parameter(board_content);
}

char *get_board_model_content(board_model_content *object)
{
    return object->board_content;
}

void clear_board_model_content(board_model_content *object)
{
    free(object);
}
