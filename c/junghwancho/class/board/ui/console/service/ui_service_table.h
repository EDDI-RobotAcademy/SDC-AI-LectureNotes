#ifndef __UI_SERVICE_TABLE_H__
#define __UI_SERVICE_TABLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ui_service.h"

typedef void * (* ui_service_call_ptr_t) (void *);

void *ui_service_not_implemented (void *);

extern const ui_service_call_ptr_t ui_service_table[UI_SERVICE_BUFFER_COUNT];

#ifdef __cplusplus
}
#endif

#endif