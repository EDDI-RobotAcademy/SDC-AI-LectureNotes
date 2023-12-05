//
// Created by eddi on 23. 12. 5.
//

#include "AccountController.h"

AccountController::AccountController(std::shared_ptr<AccountService> accountService) : accountService(accountService) { }

std::vector<AccountRegisterResponseForm> AccountController::accountRegister()
{

}