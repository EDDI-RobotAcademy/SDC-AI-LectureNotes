//
// Created by eddi on 23. 12. 4.
//

#ifndef CLASS_TEST_CONSOLEUISERVICE_H
#define CLASS_TEST_CONSOLEUISERVICE_H

#include <vector>

/*
#include "../handler/create/UiServiceCreateHandler.h"
#include "../handler/exit/UiServiceExitHandler.h"
#include "../handler/list/UiServiceListHandler.h"
#include "../handler/modify/UiServiceModifyHandler.h"
#include "../handler/read/UiServiceReadHandler.h"
#include "../handler/remove/UiServiceRemoveHandler.h"
*/

#include <string>

#include "../controller/request/ConsoleUiAccountLoginRequest.h"

class ConsoleUiService {

public:
    virtual ~ConsoleUiService() = default;

    virtual int BoardReadRequestForm() = 0;

    // 다 타입이 지정되어야 한다
    virtual void makeAccountLoginRequestForm() = 0;
//    virtual AccountRegisterRequestForm *makeAccountRegisterRequestForm(std::string id, std::string pw) = 0;

//    virtual BoardRequestFormEdit *makeBoardEditRequestForm(int readNo) = 0;
//    virtual BoardRequestFormWrite *makeBoardWriteRequestForm(std::string title, std::string content) = 0;


};

#endif //CLASS_TEST_CONSOLEUISERVICE_H
