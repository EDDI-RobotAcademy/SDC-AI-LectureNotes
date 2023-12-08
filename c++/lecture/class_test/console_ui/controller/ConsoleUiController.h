//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_CONSOLEUICONTROLLER_H
#define CLASS_TEST_CONSOLEUICONTROLLER_H

#include <memory>
#include <vector>
#include <functional>

#include "../service/ConsoleUiService.h"
#include "ConsoleUiControllerCommand.h"

class ConsoleUiController {
private:
    std::shared_ptr<ConsoleUiService> consoleUiService;

    static int currentReadBoardNo;
    static ConsoleUiControllerCommand currentState;

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
    void uiExit();

    void uiEngineStart();

    using CommandFunction = void (*)(ConsoleUiController*, void*);
    std::vector<CommandFunction> commandTable;

    void initializeCommandTable();
    void executeCommand(ConsoleUiControllerCommand command, void* data);

    void uiIntroduce(int sessionId);

    static int getCurrentReadBoardNo();
    static void setCurrentReadBoardNo(int boardNo);

    static ConsoleUiControllerCommand getCurrentState();

    static void setCurrentState(ConsoleUiControllerCommand currentState);
};


#endif //CLASS_TEST_CONSOLEUICONTROLLER_H
