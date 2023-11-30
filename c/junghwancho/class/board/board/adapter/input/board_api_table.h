#ifndef __BOARD_API_TABLE_H__
#define __BOARD_API_TABLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_api.h"

typedef void * (* board_api_call_ptr_t) (void *);

void *board_api_not_implemented (void *);

extern const board_api_call_ptr_t board_api_table[BOARD_API_BUFFER_COUNT];

#ifdef __cplusplus
}
#endif

#endif