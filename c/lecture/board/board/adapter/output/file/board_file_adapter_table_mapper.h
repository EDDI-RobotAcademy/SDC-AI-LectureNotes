#ifndef __BOARD_FILE_ADAPTER_TABLE_MAPPER_H__
#define __BOARD_FILE_ADAPTER_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_file_adapter_table.h"
#include "handler/board_file_adapter_handler.h"

#define __BOARD_FILE_ADAPTER_TABLE(number, function_prototype) [number] = function_prototype,

__BOARD_FILE_ADAPTER_TABLE(BOARD_FILE_ADAPTER_FIND_ALL, find_all_from_file)

#ifdef __cplusplus
}
#endif

#endif