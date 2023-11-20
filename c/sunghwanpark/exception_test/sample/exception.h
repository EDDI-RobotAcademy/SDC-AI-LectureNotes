#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <setjmp.h>

extern jmp_buf global_exception_buffer;

bool divide_by_zero(int target, int zero, jmp_buf env);
bool array_index_exceed(int *array, int index, jmp_buf env);
void just_test(void);

#ifdef __cplusplus
}
#endif

#endif