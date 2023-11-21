#include "board_api_modify_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/modify/board_service_modify_handler.h"
#include "../../../../application/services/board_service_table.h"

#include <stdio.h>

void board_api_modify(void *request_form)
{
    printf("board api: 게시물을 수정합니다!\n");

    board_service_table[BOARD_SERVICE_MODIFY](NULL);
}