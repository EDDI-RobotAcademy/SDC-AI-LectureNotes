#ifndef __BOARD_SERVICE_TABLE_H__
#define __BOARD_SERVICE_TABLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_service.h"

typedef void (* board_service_call_ptr_t) (void *);

void board_service_not_implemented (void *);

extern const board_service_call_ptr_t board_service_table[BOARD_SERVICE_BUFFER_COUNT];

#ifdef __cplusplus
}
#endif

#endif