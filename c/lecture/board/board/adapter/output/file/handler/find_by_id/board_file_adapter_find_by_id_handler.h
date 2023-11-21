#ifndef __BOARD_FILE_ADAPTER_FIND_BY_ID_HANDLER_H__
#define __BOARD_FILE_ADAPTER_FIND_BY_ID_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../repository/in_memory_board.h"

in_memory_board *find_by_id_from_file(void *);

#ifdef __cplusplus
}
#endif

#endif