//
// Created by eddi on 23. 12. 8.
//

#ifndef NEWUI_CONSOLEUIACCOUNTLOGINREQUEST_H
#define NEWUI_CONSOLEUIACCOUNTLOGINREQUEST_H

#include <string>
#include "../ConsoleUiController.h"

class ConsoleUiAccountLoginRequest {
private:
    std::string id;
    std::string pw;
public:
    ConsoleUiAccountLoginRequest();
    ConsoleUiAccountLoginRequest(std::string, std::string);
    void printConsoleUiAccountLoginRequest(ConsoleUiAccountLoginRequest request);
    ~ConsoleUiAccountLoginRequest();
};


#endif //NEWUI_CONSOLEUIACCOUNTLOGINREQUEST_H
