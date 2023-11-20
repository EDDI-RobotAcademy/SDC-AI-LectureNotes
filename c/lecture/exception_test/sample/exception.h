#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <setjmp.h>

#define DIVIDE_BY_ZERO      3

extern jmp_buf global_exception_buffer;

int divide_by_zero(int target, int zero);
bool array_index_exceed(int *array, int index, jmp_buf env);
void exception_setup_table(void);
void just_test(void);

#ifdef __cplusplus
}
#endif

#endif
