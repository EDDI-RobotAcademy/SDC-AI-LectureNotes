//
// Created by eddi on 23. 12. 5.
//

#include "AccountServiceImpl.h"
#include "response/AccountRegisterResponse.h"

AccountServiceImpl::AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository) : accountRepository(accountRepository) { }

AccountRegisterResponse *
        AccountServiceImpl::create(AccountRegisterRequest *request)
{
    if (accountRepository->getBoolWithFindByAccountId(request->getAccountId())) {
        return nullptr;
    }

    Account *account = accountRepository->save(request->toAccount());

    if (account != nullptr) {
        return new AccountRegisterResponse(true);
    }

    return nullptr;
}

AccountLoginResponse *
AccountServiceImpl::signIn(AccountLoginRequest *request)
{
    std::optional<Account> accountOpt = accountRepository->findByAccountId(request->getAccountId());

    if (accountOpt.has_value()) {
        std::cout << "매칭되는 사용자를 찾았습니다" << std::endl;
        Account account = accountOpt.value();

        if (account.get_password() == request->getPassword()) {
            return new AccountLoginResponse(true);
        } else {
            std::cout << "사용자 인증에 실패하였습니다" << std::endl;
            return nullptr;
        }
    } else {
        std::cout << "사용자 계정을 찾지 못했습니다" << std::endl;
        return nullptr;
    }

    return nullptr;
}

void AccountServiceImpl::signOut(int sessionId)
{
    // 사실 이러면 안되지만 적당히 퉁칩시다.
    accountRepository->deleteSession(sessionId);
}

AccountServiceImpl& AccountServiceImpl::getInstance(
        std::shared_ptr<AccountRepository> accountRepository)
{
    static AccountServiceImpl instance(accountRepository);
    return instance;
}