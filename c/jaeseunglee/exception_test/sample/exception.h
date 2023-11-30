#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <setjmp.h>

#define DIVIDE_BY_ZERO      3
#define ARRAY_INDEX_EXCEED  9

extern jmp_buf global_exception_buffer;

int divide_by_zero(int target, int zero);
void array_index_exceed(int index);
void exception_setup_table(void);

#ifdef __cplusplus
}
#endif

#endif
