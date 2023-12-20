//
// Created by eddi on 23. 12. 6.
//

#ifndef CLASS_TEST_CONSOLEUIREPOSITORY_H
#define CLASS_TEST_CONSOLEUIREPOSITORY_H

class ConsoleUiRepository {
public:
    virtual ~ConsoleUiRepository() = default;
    virtual int getSignInSession() = 0;
    virtual void storeSignInSession(int uniqueSessionId) = 0;
};

#endif //CLASS_TEST_CONSOLEUIREPOSITORY_H
