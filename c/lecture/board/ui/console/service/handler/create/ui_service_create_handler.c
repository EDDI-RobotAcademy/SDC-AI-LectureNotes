#include "ui_service_create_handler.h"

#include "../../../../../board/adapter/input/request_form/board_api_create_request_form.h"
#include "../../../user_keyboard/user_keyboard_input.h"

void *ui_service_create(void *nothing)
{
    char title[32] = { 0 };
    char writer[32] = { 0 };
    char content[128] = { 0 };

    board_api_create_request_form *create_request_form;

    get_user_keyboard_input_with_message("제목을 입력하세요: ", title);
    get_user_keyboard_input_with_message("작성자를 입력하세요: ", writer);
    get_user_keyboard_input_with_message("내용을 입력하세요: ", content);

    printf("제목: %s, 작성자: %s, 내용: %s\n", title, writer, content);

    create_request_form = init_board_api_create_request_form(
        title, writer, content);

    return create_request_form;
}