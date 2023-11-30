#ifndef __BOARD_FILE_ADAPTER_TABLE_H__
#define __BOARD_FILE_ADAPTER_TABLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_file_adapter.h"
#include "repository/in_memory_board.h"

typedef void * (* board_file_adapter_call_ptr_t) (void *);

void *board_file_adapter_not_implemented (void *);

extern const board_file_adapter_call_ptr_t board_file_adapter_table[BOARD_FILE_ADAPTER_BUFFER_COUNT];

#ifdef __cplusplus
}
#endif

#endif