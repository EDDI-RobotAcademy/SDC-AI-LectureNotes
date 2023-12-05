//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREGISTER_RESPONSEFORM_H
#define CLASS_TEST_ACCOUNTREGISTER_RESPONSEFORM_H


class AccountRegisterResponseForm {
private:
    bool is_register_success;

public:
    AccountRegisterResponseForm (bool is_register_success);
    bool getIsRegisterSuccess() const;
};


#endif //CLASS_TEST_ACCOUNTREGISTER_RESPONSEFORM_H
