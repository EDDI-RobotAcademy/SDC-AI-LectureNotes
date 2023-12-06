//
// Created by oem on 23. 12. 6.
//

#ifndef CLASS_TEST_ACCOUNTLOGINRESPONSEFORM_H
#define CLASS_TEST_ACCOUNTLOGINRESPONSEFORM_H


class AccountLoginResponseForm {
private:
    int login_account_unique_id;

public:
    AccountLoginResponseForm (int id);

    int getLoginAccountUniqueId();
};


#endif //CLASS_TEST_ACCOUNTLOGINRESPONSEFORM_H
