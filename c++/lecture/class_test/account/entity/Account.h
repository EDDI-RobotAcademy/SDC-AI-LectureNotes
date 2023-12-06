//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNT_H
#define CLASS_TEST_ACCOUNT_H

#include <string>
#include <chrono>
#include <iostream>

class Account {
private:
    int id;
    std::string account_id;
    std::string password;

    std::chrono::system_clock::time_point reg_date;
    std::chrono::system_clock::time_point upd_date;

public:
    Account(const std::string& account_id, const std::string& password);
    Account(int id, const std::string& account_id, const std::string& password);
    Account(int id, const std::string& account_id, const std::string& password,
          const std::string& reg_date, const std::string& upd_date);

    int get_id();
    std::string get_account_id();
    std::string get_password();
    void printAccountInfo();
};


#endif //CLASS_TEST_ACCOUNT_H
