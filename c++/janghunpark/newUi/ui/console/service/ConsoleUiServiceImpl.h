//
// Created by eddi on 23. 12. 4.
//


#ifndef CLASS_TEST_CONSOLEUISERVICEIMPL_H
#define CLASS_TEST_CONSOLEUISERVICEIMPL_H

#include <string>
#include <vector>

#include "ConsoleUiService.h"

class ConsoleUiServiceImpl : public ConsoleUiService {
public:
    ConsoleUiServiceImpl();

    int BoardReadRequestForm() override;

    void makeAccountLoginRequestForm() override;
//    AccountRequestRegister *makeAccountRegisterRequestForm(std::string id, std::string pw) override;

//    BoardRequestFormEdit *makeBoardEditRequestForm(int readNo) override;
//    BoardRequestFormWrite *makeBoardWriteRequestForm(std::string title, std::string content) override;
};

#endif //CLASS_TEST_CONSOLEUISERVICEIMPL_H