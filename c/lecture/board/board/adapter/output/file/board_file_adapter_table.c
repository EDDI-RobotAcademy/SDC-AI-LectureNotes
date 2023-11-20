#include "board_file_adapter_table.h"
#include "handler/find_all/board_file_adapter_find_all_handler.h"
#include "handler/save/board_file_adapter_save_handler.h"
#include "handler/find_by_id/board_file_adapter_find_by_id_handler.h"

#include <stdio.h>

void board_file_adapter_not_implemented (void)
{
    printf("Board File Adapter: 아직 구현되지 않은 기능입니다!\n");
}

const board_file_adapter_call_ptr_t board_file_adapter_table[BOARD_FILE_ADAPTER_BUFFER_COUNT] =
{
    [0 ... BOARD_FILE_ADAPTER_BUFFER] = board_file_adapter_not_implemented,
    #include "board_file_adapter_table_mapper.h"
};