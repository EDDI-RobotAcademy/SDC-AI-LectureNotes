#include "ui_service.h"

#include "ui_service_table.h"
#include "handler/create/ui_service_create_handler.h"
#include "handler/list/ui_service_list_handler.h"
#include "handler/read/ui_service_read_handler.h"
#include "handler/modify/ui_service_modify_handler.h"
#include "handler/remove/ui_service_remove_handler.h"
#include "handler/exit/ui_service_exit_handler.h"

#include <stdio.h>

void *ui_service_not_implemented (void *nothing)
{
    printf("UI Service: 아직 구현되지 않은 기능입니다!\n");
    return NULL;
}

const ui_service_call_ptr_t ui_service_table[UI_SERVICE_BUFFER_COUNT] =
{
    [0 ... UI_SERVICE_BUFFER] = ui_service_not_implemented,
    #include "ui_service_table_mapper.h"
};