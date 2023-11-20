#include "board_service.h"
#include "handler/board_service_handler.h"
#include "board_service_table.h"

#include <stdio.h>

void board_service_not_implemented (void)
{
    printf("Board Service: 아직 구현되지 않은 기능입니다!\n");
}

const board_service_call_ptr_t board_service_table[BOARD_SERVICE_BUFFER_COUNT] =
{
    [0 ... BOARD_SERVICE_BUFFER] = board_service_not_implemented,
    #include "board_service_table_mapper.h"
};