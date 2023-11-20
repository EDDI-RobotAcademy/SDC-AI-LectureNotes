#ifndef __BOARD_SERVICE_TABLE_MAPPER_H__
#define __BOARD_SERVICE_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_service_table.h"
#include "handler/board_service_handler.h"

#define __BOARD_SERVICE_TABLE(number, function_prototype) [number] = function_prototype

__BOARD_SERVICE_TABLE(BOARD_SERVICE_GET_LIST, board_service_get_list)

#ifdef __cplusplus
}
#endif

#endif