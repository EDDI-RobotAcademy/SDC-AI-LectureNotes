#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <wctype.h>
#include <wchar.h>

#include <stdbool.h>

bool is_ascii(const char *str);
void trim_whitespaces(char **str);
void trim_wide_whitespaces(wchar_t *str);

#ifdef __cplusplus
}
#endif

#endif