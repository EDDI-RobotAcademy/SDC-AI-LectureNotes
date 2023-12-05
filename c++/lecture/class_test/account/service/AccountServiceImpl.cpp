//
// Created by eddi on 23. 12. 5.
//

#include "AccountServiceImpl.h"
#include "response/AccountRegisterResponse.h"

AccountServiceImpl::AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository) : accountRepository(accountRepository) { }

AccountRegisterResponse *
        AccountServiceImpl::create(AccountRegisterRequest *request)
{
    Account *account = accountRepository->save(request->toAccount());
    return new AccountRegisterResponse(account->get_id());
}

AccountServiceImpl& AccountServiceImpl::getInstance(
        std::shared_ptr<AccountRepository> accountRepository)
{
    static AccountServiceImpl instance(accountRepository);
    return instance;
}