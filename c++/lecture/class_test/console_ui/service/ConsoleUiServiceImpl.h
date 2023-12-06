//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_CONSOLEUISERVICEIMPL_H
#define CLASS_TEST_CONSOLEUISERVICEIMPL_H

#include <memory>
#include "ConsoleUiService.h"
#include "../../account/controller/request_form/AccountRegisterRequestForm.h"
#include "../../account/controller/request_form/AccountLoginRequestForm.h"

#include "../repository/ConsoleUiRepository.h"

class ConsoleUiServiceImpl : public ConsoleUiService {
private:
    std::shared_ptr<ConsoleUiRepository> consoleUiRepository;

public:
    ConsoleUiServiceImpl(std::shared_ptr<ConsoleUiRepository> consoleUiRepository);

    AccountRegisterRequestForm *makeAccountRegisterForm() override;
    AccountLoginRequestForm *makeAccountLoginForm() override;

    BoardRegisterRequestForm *makeBoardRegisterForm(int sessionId) override;

    void storeSession(int uniqueId) override;
    int getSignInSession() override;
};


#endif //CLASS_TEST_CONSOLEUISERVICEIMPL_H
