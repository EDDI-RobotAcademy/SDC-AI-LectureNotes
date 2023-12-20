//
// Created by eddi on 23. 12. 6.
//

#include "AccountLoginResponse.h"

AccountLoginResponse::AccountLoginResponse (int login_account_unique_id)
        : login_account_unique_id(login_account_unique_id) { }

AccountLoginResponseForm *AccountLoginResponse::toResponseForm()
{
    return new AccountLoginResponseForm(login_account_unique_id);
}
