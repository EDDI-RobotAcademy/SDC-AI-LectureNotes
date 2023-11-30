#include "ui_service_read_handler.h"

#include <stdlib.h>

void *ui_service_read(void *nothing)
{
    char board_id[32] = { 0 };

    get_user_keyboard_input_with_message("읽고 싶은 게시물 번호를 입력하세요: ", board_id);

    return atoi(board_id);
}