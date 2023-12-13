//
// Created by junghwan on 23. 12. 6.
//

#ifndef CLASS_TEST_CONSOLEUICONTROLLER_H
#define CLASS_TEST_CONSOLEUICONTROLLER_H

#include <memory>

#include "../service/ConsoleUiService.h"
#include "../service/ConsoleUiServiceImpl.h"

class ConsoleUiController {

private:
    std::shared_ptr<ConsoleUiServiceImpl> consoleUiService;

public:
   // ConsoleUiController();
    ConsoleUiController(std::shared_ptr<ConsoleUiServiceImpl> consoleUiService);

    void uiAccountLogin();
    void uiAccountRegister();

    void uiBoardList();
    void uiBoardRead();
    void uiBoardWrite();
    void uiBoardEdit();
    void uiBoardRemove();

    void uiEngineStart();
};


#endif //CLASS_TEST_CONSOLEUICONTROLLER_H

