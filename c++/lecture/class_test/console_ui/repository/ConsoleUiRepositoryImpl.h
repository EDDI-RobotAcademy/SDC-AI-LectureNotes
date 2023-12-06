//
// Created by eddi on 23. 12. 6.
//

#ifndef CLASS_TEST_CONSOLEUIREPOSITORYIMPL_H
#define CLASS_TEST_CONSOLEUIREPOSITORYIMPL_H

#include "ConsoleUiRepository.h"

class ConsoleUiRepositoryImpl : public ConsoleUiRepository {
public:
    static ConsoleUiRepositoryImpl& getInstance();

    int getSignInSession() override;
    void storeSignInSession(int uniqueSessionId) override;
};


#endif //CLASS_TEST_CONSOLEUIREPOSITORYIMPL_H
