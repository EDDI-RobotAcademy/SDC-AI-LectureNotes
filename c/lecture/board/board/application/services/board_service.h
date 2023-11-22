#ifndef __BOARD_SERVICE_H__
#define __BOARD_SERVICE_H__

#ifdef __cplusplus
extern "C" {
#endif

enum board_service
{
    BOARD_SERVICE_GET_LIST,
    BOARD_SERVICE_CREATE,
    BOARD_SERVICE_GET_ONE,
    BOARD_SERVICE_MODIFY,
    BOARD_SERVICE_REMOVE,
    BOARD_SERVICE_END
};

#define BOARD_SERVICE_BUFFER_COUNT          (BOARD_SERVICE_END)
#define BOARD_SERVICE_BUFFER                ((BOARD_SERVICE_END) - 1)

#ifdef __cplusplus
}
#endif

#endif