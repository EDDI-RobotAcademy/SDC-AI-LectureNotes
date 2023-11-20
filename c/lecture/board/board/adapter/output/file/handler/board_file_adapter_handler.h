#ifndef __BOARD_FILE_ADAPTER_HANDLER_H__
#define __BOARD_FILE_ADAPTER_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../repository/in_memory_board.h"

in_memory_board **find_all_from_file(void);

#ifdef __cplusplus
}
#endif

#endif