#ifndef __BOARD_API_TABLE_MAPPER_H__
#define __BOARD_API_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_api_table.h"
#include "handler/board_api_handler.h"

#define __BOARD_API_TABLE(number, function_prototype) [number] = function_prototype

__BOARD_API_TABLE(BOARD_API_LIST, board_api_list)

#ifdef __cplusplus
}
#endif

#endif