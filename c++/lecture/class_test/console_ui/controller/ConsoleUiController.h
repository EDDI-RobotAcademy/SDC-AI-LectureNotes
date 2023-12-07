//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_CONSOLEUICONTROLLER_H
#define CLASS_TEST_CONSOLEUICONTROLLER_H

#include <memory>
#include <vector>

#include "../service/ConsoleUiService.h"

class ConsoleUiController {
private:
    std::shared_ptr<ConsoleUiService> consoleUiService;

public:
    ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService);
    static ConsoleUiController& getInstance(std::shared_ptr<ConsoleUiService> consoleUiService);
    static ConsoleUiController& getInstance();

    void uiAccountRegister();
    void uiAccountLogin();
    void uiAccountLogout();

    void uiBoardRegister();
    void uiBoardRead();
    void uiBoardList();
    void uiBoardModify(int boardNo);
    void uiBoardRemove(int boardNo);
};


#endif //CLASS_TEST_CONSOLEUICONTROLLER_H
