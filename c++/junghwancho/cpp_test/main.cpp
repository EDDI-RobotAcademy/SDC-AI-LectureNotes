#include <iostream>

#include "boardDB/BoardDB.h"
#include "accountDB/AccountDB.h"



int main() {
    std::cout << "Hello, World!" << std::endl;

    BoardDB::boardDBCall();
    AccountDB::accountDBCall();

    return 0;
}
