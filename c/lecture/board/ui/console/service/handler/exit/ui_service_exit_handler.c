#include "ui_service_exit_handler.h"

#include <stdio.h>
#include <stdlib.h>

void *ui_service_exit(void *nothing)
{
    printf("프로그램을 종료합니다!\n");
    exit(0);
}
