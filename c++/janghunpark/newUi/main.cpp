#include <iostream>

#include "ui/console/controller/ConsoleUiController.h"
#include "ui/console/service/ConsoleUiService.h"
#include "ui/console/service/ConsoleUiServiceImpl.h"

int main() {

    auto ConsoleUiService = std::make_shared<ConsoleUiServiceImpl>();
    ConsoleUiController uiController(ConsoleUiService);
    uiController.uiEngineStart();

    return 0;
}
