from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from account.service.AccountService import AccountService
from account.service.request.AccountRegisterRequest import AccountRegisterRequest
from account.service.response.AccountRegisterResponse import AccountRegisterResponse


class AccountServiceImpl(AccountService):
    __instance = None

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("TaskManageServiceImpl 생성자 호출")
        self.__accountRepository = AccountRepositoryImpl()

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def registerAccount(self, *args, **kwargs):
        cleanedElements = args[0]

        # for i, element in enumerate(cleanedElements):
        #     print(f"각각의 요소 {i + 1}: {element}")

        accountRegisterRequest = AccountRegisterRequest(cleanedElements[0], cleanedElements[1])
        storedAccount = self.__accountRepository.save(accountRegisterRequest.toAccount())

        return AccountRegisterResponse(storedAccount.getId())

    