#ifndef __BOARD_FILE_ADAPTER_H__
#define __BOARD_FILE_ADAPTER_H__

#ifdef __cplusplus
extern "C" {
#endif

enum board_file_adapter
{
    BOARD_FILE_ADAPTER_FIND_ALL,
    BOARD_FILE_ADAPTER_FIND_BY_ID,
    BOARD_FILE_ADAPTER_SAVE,
    BOARD_FILE_ADAPTER_DELETE,
    BOARD_FILE_ADAPTER_END
};

#define BOARD_FILE_ADAPTER_BUFFER_COUNT          (BOARD_FILE_ADAPTER_END)
#define BOARD_FILE_ADAPTER_BUFFER                ((BOARD_FILE_ADAPTER_END) - 1)

#ifdef __cplusplus
}
#endif

#endif