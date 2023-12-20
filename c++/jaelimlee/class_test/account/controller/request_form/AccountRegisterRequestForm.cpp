//
// Created by eddi on 23. 12. 5.
//

#include "AccountRegisterRequestForm.h"

AccountRegisterRequestForm::AccountRegisterRequestForm(
        const std::string& account_id, const std::string& password) :
        account_id(account_id), password(password) { }

AccountRegisterRequest *AccountRegisterRequestForm::toAccountRegisterRequest()
{
    return new AccountRegisterRequest(account_id, password);
}
