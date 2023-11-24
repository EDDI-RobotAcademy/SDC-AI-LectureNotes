#include "ui_service_remove_handler.h"

#include <stdio.h>
#include <stdlib.h>

void *ui_service_remove(void *nothing)
{
    char board_id[32] = { 0 };
    unsigned int id;

    get_user_keyboard_input_with_message("삭제하고 싶은 게시물 번호를 입력하세요: ", board_id);
    id = atoi(board_id);

    return id;
}
