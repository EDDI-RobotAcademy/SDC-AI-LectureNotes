#include "board_model_writer.h"

#include "../../../utility/trim.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool check_board_writer_validation(char *board_writer)
{
    trim_whitespaces(&board_writer);

    if (board_writer == NULL)
    {
        printf("작성자는 필수입니다!\n");
        return false;
    }

    if (!strncmp(board_writer, "\0", 1))
    {
        printf("작성자 이름을 올바르게 작성하세요!\n");
        return false;
    }

    if (strlen(board_writer) >= MAX_WRITER_LENGTH)
    {
        printf("작성자의 최대 길이는 %d 로 제한됩니다.\n", MAX_WRITER_LENGTH - 1);
        return false;
    }

    return true;
}

board_model_writer *init_board_model_writer_with_parameter(char *board_writer)
{
    int board_writer_length;
    board_model_writer *tmp_writer;

    if (check_board_writer_validation(board_writer))
    {
        tmp_writer = (board_model_writer *)malloc(sizeof(board_model_writer));
        board_writer_length = strlen(board_writer);

        strncpy(tmp_writer->board_writer, board_writer, board_writer_length);

        return tmp_writer;
    }

    return NULL;
}

char *get_board_model_writer(board_model_writer *object)
{
    return object->board_writer;
}

void clear_board_model_writer(board_model_writer *object)
{
    free(object);
}
