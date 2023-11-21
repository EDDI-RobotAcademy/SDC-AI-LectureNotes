#include "board_api_list_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/get_list/board_service_get_list_handler.h"
#include "../../../../application/services/board_service_table.h"

#include <stdio.h>

void board_api_list(void *request_form)
{
    printf("board api: 게시판 리스트를 조회합니다!\n");

    board_service_table[BOARD_SERVICE_GET_LIST](NULL);
}
