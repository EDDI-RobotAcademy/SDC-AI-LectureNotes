#include "board_api_read_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/create/board_service_create_handler.h"
#include "../../../../application/services/board_service_table.h"

#include <stdio.h>

void *board_api_read(void *request_form)
{
    printf("board api: 게시물을 읽습니다!\n");

    board_service_table[BOARD_SERVICE_GET_ONE](NULL);

    return NULL;
}