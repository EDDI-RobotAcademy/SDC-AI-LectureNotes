#include <gtest/gtest.h>

#include "../../../../ui/console/service/ui_service.h"
#include "../../../../ui/console/service/ui_service_table.h"

TEST(ui_console_service, 게시판에_게시물_작성하기)
{
    int user_choice_command_number = UI_SERVICE_CREATE;

    ui_service_table[user_choice_command_number](NULL);
}

