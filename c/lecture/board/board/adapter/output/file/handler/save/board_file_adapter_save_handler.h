#ifndef __BOARD_FILE_ADAPTER_SAVE_HANDLER_H__
#define __BOARD_FILE_ADAPTER_SAVE_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../repository/in_memory_board.h"

in_memory_board **save_to_file(void);

#ifdef __cplusplus
}
#endif

#endif