//
// Created by eddi on 23. 12. 5.
//

#include "AccountRegisterResponse.h"
#include "../../controller/response_form/AccountRegisterResponseForm.h"

AccountRegisterResponse::AccountRegisterResponse (int id) : login_account_unique_id(id) { }

AccountRegisterResponseForm *AccountRegisterResponse::toResponseForm()
{
    return new AccountRegisterResponseForm(login_account_unique_id);
}