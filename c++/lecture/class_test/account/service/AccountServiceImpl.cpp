//
// Created by eddi on 23. 12. 5.
//

#include "AccountServiceImpl.h"
#include "response/AccountRegisterResponse.h"

AccountServiceImpl::AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository) : accountRepository(accountRepository) { }

AccountRegisterResponse *
        AccountServiceImpl::create(AccountRegisterRequest *request)
{
    if (accountRepository->findByAccountId(request->getAccountId())) {
        return nullptr;
    }

    Account *account = accountRepository->save(request->toAccount());

    if (account != nullptr) {
        return new AccountRegisterResponse(true);
    }

}

AccountServiceImpl& AccountServiceImpl::getInstance(
        std::shared_ptr<AccountRepository> accountRepository)
{
    static AccountServiceImpl instance(accountRepository);
    return instance;
}