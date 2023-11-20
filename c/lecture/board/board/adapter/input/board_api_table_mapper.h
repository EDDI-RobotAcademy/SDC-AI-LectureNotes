#ifndef __BOARD_API_TABLE_MAPPER_H__
#define __BOARD_API_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_api_table.h"
#include "handler/list/board_api_list_handler.h"
#include "handler/register/board_api_register_handler.h"

#define __BOARD_API_TABLE(number, function_prototype) [number] = function_prototype,

__BOARD_API_TABLE(BOARD_API_LIST, board_api_list)
__BOARD_API_TABLE(BOARD_API_CREATE, board_api_register)

#ifdef __cplusplus
}
#endif

#endif