from account.entity.Session import Session
from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from account.repository.SessionRepositoryImpl import SessionRepositoryImpl
from account.service.AccountService import AccountService
from account.service.request.AccountLoginRequest import AccountLoginRequest
from account.service.request.AccountRegisterRequest import AccountRegisterRequest
from account.service.response.AccountLoginResponse import AccountLoginResponse
from account.service.response.AccountRegisterResponse import AccountRegisterResponse


class AccountServiceImpl(AccountService):
    __instance = None

    def __new__(cls, accountRepository, sessionRepository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__accountRepository = accountRepository
            cls.__instance.__sessionRepository = sessionRepository
        return cls.__instance
    #
    # def __init__(self):
    #     print("AccountServiceImpl 생성자 호출")

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def registerAccount(self, *args, **kwargs):
        print("registerAccount()")
        print(f"args: {args}")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        # for i, element in enumerate(cleanedElements):
        #     print(f"각각의 요소 {i + 1}: {element}")

        accountRegisterRequest = AccountRegisterRequest(*cleanedElements)
        accountId = accountRegisterRequest.getAccountId()
        foundAccount = self.__accountRepository.findByAccountId(accountId)
        if foundAccount is not None:
            return AccountRegisterResponse(False)

        storedAccount = self.__accountRepository.save(accountRegisterRequest.toAccount())

        if storedAccount.getId() is not None:
            return AccountRegisterResponse(True)

        return AccountRegisterResponse(False)

    def loginAccount(self, *args, **kwargs):
        print("loginAccount()")
        print(f"args: {args}")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        accountLoginRequest = AccountLoginRequest(*cleanedElements)
        foundAccount = self.__accountRepository.findByAccountId(accountLoginRequest.getAccountId())
        print(f"foundAccount: {foundAccount}")
        if foundAccount is None:
            return AccountLoginResponse(-1)

        if foundAccount.checkPassword(accountLoginRequest.getPassword()):
            sessionRepository = SessionRepositoryImpl.getInstance()
            accountSession = Session(foundAccount.getId())
            sessionRepository.save(accountSession)

            return AccountLoginResponse(foundAccount.getId())

        return AccountLoginResponse(-1)

    