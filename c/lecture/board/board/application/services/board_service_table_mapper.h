#ifndef __BOARD_SERVICE_TABLE_MAPPER_H__
#define __BOARD_SERVICE_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_service_table.h"
#include "handler/get_list/board_service_get_list_handler.h"
#include "handler/create/board_service_create_handler.h"
#include "handler/get_one/board_service_get_one_handler.h"

#define __BOARD_SERVICE_TABLE(number, function_prototype) [number] = function_prototype,

__BOARD_SERVICE_TABLE(BOARD_SERVICE_GET_LIST, board_service_get_list)
__BOARD_SERVICE_TABLE(BOARD_SERVICE_CREATE, board_service_create)
__BOARD_SERVICE_TABLE(BOARD_SERVICE_GET_ONE, board_service_get_one)

#ifdef __cplusplus
}
#endif

#endif