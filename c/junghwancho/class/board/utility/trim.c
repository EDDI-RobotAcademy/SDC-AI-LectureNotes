#include "trim.h"

#include <string.h>
#include <ctype.h>

#include <stdio.h>

bool is_ascii(const char *str) 
{
    while (*str) {
        if ((unsigned char)(*str) > 127) {
            return false;
        }
        str++;
    }
    return true;
}

void trim_whitespaces(char **str)
{
    if (str == NULL || *str == NULL) { return; }

    while (isspace((unsigned char)**str)) {
        (*str)++;
    }

    char *end = *str + strlen(*str) - 1;
    while (end > *str && isspace((unsigned char)*end)) {
        end--;
    }

    *(end + 1) = '\0';
}

void trim_wide_whitespaces(wchar_t *str)
{
    if (str == NULL) { return; }

    // 앞쪽 공백 제거
    while (iswspace(*str)) {
        str++;
    }

    // 뒤쪽 공백 제거
    wchar_t *end = str + wcslen(str) - 1;
    while (end > str && iswspace(*end)) {
        end--;
    }

    // NULL 문자 추가하여 문자열 종료
    *(end + 1) = L'\0';
}