import json

from account.entity.Session import Session
from account.repository.AccountRepositoryImpl import AccountRepositoryImpl

from account.service.request.AccountDeleteRequest import AccountDeleteRequest
from account.service.request.AccountLoginRequest import AccountLoginRequest
from account.service.request.AccountLogoutRequest import AccountLogoutRequest
from account.service.request.AccountRegisterRequest import AccountRegisterRequest
from account.service.response.AccountDeleteResponse import AccountDeleteResponse
from account.service.response.AccountLoginResponse import AccountLoginResponse
from account.service.response.AccountLogoutResponse import AccountLogoutResponse
from account.service.response.AccountRegisterResponse import AccountRegisterResponse
from product.service.ProductService import ProductService
from product.service.request.ProductRegisterRequest import ProductRegisterRequest
from product.service.response.ProductListResponse import ProductListResponse
from product.service.response.ProductRegisterResponse import ProductRegisterResponse


class ProductServiceImpl(ProductService):
    __instance = None

    def __new__(cls, accountRepository, productRepository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__accountRepository = accountRepository
            cls.__instance.__productRepository = productRepository
        return cls.__instance

    #
    # def __init__(self):
    #     print("AccountServiceImpl 생성자 호출")

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def listProduct(self):
        productList = self.__productRepository.findAll()
        productConvertedList = []

        for product in productList:
            productConvertedList.append({
                'productId': product.getId(),
                'name': product.getName(),
                'price': product.getPrice(),
                'registeredAccountId': self.__accountRepository.findById(product.getRegisteredBy()).getAccountId()
            })

        productListResponse = ProductListResponse(productConvertedList)
        print(f"Listing products: {productListResponse.getProductList()}")

        return productListResponse

    def registerProduct(self, *args, **kwargs):
        print("registerProduct()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        productRegisterRequest = ProductRegisterRequest(*cleanedElements)


        storedProduct = self.__productRepository.save(productRegisterRequest.toProduct())

        if storedProduct.getId() is not None:
            foundAccount = self.__accountRepository.findById(storedProduct.getRegisteredBy())

            return ProductRegisterResponse(
                storedProduct.getId(),
                storedProduct.getName(),
                storedProduct.getPrice(),
                storedProduct.getDetails(),
                foundAccount.getAccountId()
            )

        return ProductRegisterResponse(-1, None, 0, None, None)
    #
    # def loginAccount(self, *args, **kwargs):
    #     print("loginAccount()")
    #     print(f"args: {args}")
    #
    #     cleanedElements = args[0]
    #     print(f"cleanedElements: {cleanedElements}")
    #
    #     accountLoginRequest = AccountLoginRequest(*cleanedElements)
    #     foundAccount = self.__accountRepository.findByAccountId(accountLoginRequest.getAccountId())
    #     print(f"foundAccount: {foundAccount}")
    #     if foundAccount is None:
    #         return AccountLoginResponse(-1)
    #
    #     if foundAccount.checkPassword(accountLoginRequest.getPassword()):
    #         # sessionRepository = SessionRepositoryImpl.getInstance()
    #         accountSession = Session(foundAccount.getId())
    #         # sessionRepository.save(accountSession)
    #         self.__sessionRepository.save(accountSession)
    #
    #         return AccountLoginResponse(foundAccount.getId())
    #
    #     return AccountLoginResponse(-1)
    #
    # def logoutAccount(self, *args, **kwargs):
    #     print("AccountService - logoutAccount()")
    #     print(f"args: {args}")
    #
    #     cleanedElements = args[0]
    #     print(f"cleanedElements: {cleanedElements}")
    #
    #     accountLoginRequest = AccountLogoutRequest(*cleanedElements)
    #     foundAccount = self.__accountRepository.findById(accountLoginRequest.getAccountSessionId())
    #     print(f"foundAccount: {foundAccount}")
    #     if foundAccount is None:
    #         return AccountLogoutResponse(False)
    #
    #     self.__sessionRepository.deleteBySessionId(foundAccount.getId())
    #
    #     return AccountLogoutResponse(True)
    #
    # def deleteAccount(self, *args, **kwargs):
    #     print("AccountService - deleteAccount()")
    #
    #     cleanedElements = args[0]
    #
    #     accountLoginRequest = AccountDeleteRequest(*cleanedElements)
    #     foundAccount = self.__accountRepository.findById(accountLoginRequest.getAccountSessionId())
    #     print(f"foundAccount: {foundAccount}")
    #     if foundAccount is None:
    #         return AccountDeleteResponse(False)
    #
    #     self.__sessionRepository.deleteBySessionId(foundAccount.getId())
    #     self.__accountRepository.deleteById(foundAccount.getId())
    #
    #     return AccountDeleteResponse(True)


