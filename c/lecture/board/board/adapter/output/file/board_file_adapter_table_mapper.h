#ifndef __BOARD_FILE_ADAPTER_TABLE_MAPPER_H__
#define __BOARD_FILE_ADAPTER_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_file_adapter_table.h"
#include "handler/find_all/board_file_adapter_find_all_handler.h"
#include "handler/save/board_file_adapter_save_handler.h"
#include "handler/find_by_id/board_file_adapter_find_by_id_handler.h"

#define __BOARD_FILE_ADAPTER_TABLE(number, function_prototype) [number] = function_prototype,

__BOARD_FILE_ADAPTER_TABLE(BOARD_FILE_ADAPTER_FIND_ALL, find_all_from_file)
__BOARD_FILE_ADAPTER_TABLE(BOARD_FILE_ADAPTER_SAVE, save_to_file)
__BOARD_FILE_ADAPTER_TABLE(BOARD_FILE_ADAPTER_FIND_BY_ID, find_by_id_from_file)

#ifdef __cplusplus
}
#endif

#endif