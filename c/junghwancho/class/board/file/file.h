#ifndef __FILE_H__
#define __FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define BUDDY_PAGE_SIZE          4096

bool read_file_to_make_board_list(char *read_buffer);

#ifdef __cplusplus
}
#endif

#endif