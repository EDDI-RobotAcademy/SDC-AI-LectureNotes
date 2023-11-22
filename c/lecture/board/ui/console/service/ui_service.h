#ifndef __UI_SERVICE_H__
#define __UI_SERVICE_H__

#ifdef __cplusplus
extern "C" {
#endif

enum ui_service
{
    UI_SERVICE_GET_LIST,
    UI_SERVICE_CREATE,
    UI_SERVICE_GET_ONE,
    UI_SERVICE_MODIFY,
    UI_SERVICE_REMOVE,
    UI_SERVICE_END
};

#define UI_SERVICE_BUFFER_COUNT          (UI_SERVICE_END)
#define UI_SERVICE_BUFFER                ((UI_SERVICE_END) - 1)

#ifdef __cplusplus
}
#endif

#endif