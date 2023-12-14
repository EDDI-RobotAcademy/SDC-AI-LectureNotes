//
// Created by eddi on 23. 12. 5.
//

#include "AccountRegisterResponseForm.h"

AccountRegisterResponseForm::AccountRegisterResponseForm (bool is_register_success)
                                        : is_register_success(is_register_success) { }

bool AccountRegisterResponseForm::getIsRegisterSuccess() const {
    return is_register_success;
}