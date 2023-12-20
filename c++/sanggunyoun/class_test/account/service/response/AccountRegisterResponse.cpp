//
// Created by eddi on 23. 12. 5.
//

#include "AccountRegisterResponse.h"
#include "../../controller/response_form/AccountRegisterResponseForm.h"

AccountRegisterResponse::AccountRegisterResponse (bool is_register_success)
                            : is_register_success(is_register_success) { }

AccountRegisterResponseForm *AccountRegisterResponse::toResponseForm()
{
    return new AccountRegisterResponseForm(is_register_success);
}