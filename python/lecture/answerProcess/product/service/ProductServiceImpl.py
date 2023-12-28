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
from product.service.request.ProductDeleteRequest import ProductDeleteRequest
from product.service.request.ProductReadRequest import ProductReadRequest
from product.service.request.ProductRegisterRequest import ProductRegisterRequest
from product.service.request.ProductSearchRequest import ProductSearchRequest
from product.service.request.ProductUpdateRequest import ProductUpdateRequest
from product.service.response.ProductDeleteResponse import ProductDeleteResponse
from product.service.response.ProductListResponse import ProductListResponse
from product.service.response.ProductReadResponse import ProductReadResponse
from product.service.response.ProductRegisterResponse import ProductRegisterResponse
from product.service.response.ProductUpdateResponse import ProductUpdateResponse


class ProductServiceImpl(ProductService):
    __instance = None

    def __new__(cls, accountRepository, sessionRepository, productRepository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__accountRepository = accountRepository
            cls.__instance.__sessionRepository = sessionRepository
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

    def readProduct(self, *args, **kwargs):
        print("readProduct()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        productReadRequest = ProductReadRequest(*cleanedElements)

        productId = productReadRequest.getId()

        sessionId = productReadRequest.getSessionId()
        accountSession = self.__sessionRepository.findBySessionId(sessionId)
        if accountSession is None:
            return ProductReadResponse(-1, None, 0, None, None)

        foundProduct = self.__productRepository.findById(productId)
        if foundProduct is None:
            return ProductReadResponse(-1, None, 0, None, None)

        foundAccount = self.__accountRepository.findById(sessionId)

        return ProductReadResponse(
            foundProduct.getId(),
            foundProduct.getName(),
            foundProduct.getPrice(),
            foundProduct.getDetails(),
            foundAccount.getAccountId()
        )

    def updateProduct(self, *args, **kwargs):
        print("updateProduct()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        productUpdateRequest = ProductUpdateRequest(*cleanedElements)

        sessionId = productUpdateRequest.getSessionId()
        accountSession = self.__sessionRepository.findBySessionId(sessionId)
        if accountSession is not None:
            foundProduct = self.__productRepository.findById(productUpdateRequest.getId())
        else:
            return ProductUpdateResponse(-1, None, 0, None, None)

        if foundProduct is not None:
            foundProduct.setName(productUpdateRequest.getName())
            foundProduct.setPrice(productUpdateRequest.getPrice())
            foundProduct.setDetails(productUpdateRequest.getDetails())

            savedProduct = self.__productRepository.save(foundProduct)
            foundAccount = self.__accountRepository.findById(sessionId)

            return ProductUpdateResponse(
                savedProduct.getId(),
                savedProduct.getName(),
                savedProduct.getPrice(),
                savedProduct.getDetails(),
                foundAccount.getAccountId()
            )

        return ProductUpdateResponse(-1, None, 0, None, None)

    def deleteProduct(self, *args, **kwargs):
        print("ProductService - deleteProduct()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        productDeleteRequest = ProductDeleteRequest(*cleanedElements)

        sessionAccountId = productDeleteRequest.getSessionId()
        foundAccount = self.__accountRepository.findById(sessionAccountId)

        # TODO: 여기서도 사실 각 실패 상태를 관리해서 어떤 문제인지 파악 할 수 있으면 더 좋음
        if foundAccount is None:
            print("현재 세션의 사용자를 찾을 수 없습니다")
            return ProductDeleteResponse(False)

        productId = productDeleteRequest.getId()
        foundProduct = self.__productRepository.findById(productId)
        if foundProduct is None:
            print("삭제를 요청한 상품을 찾을 수 없습니다")
            return ProductDeleteResponse(False)

        registeredAccountId = foundProduct.getRegisteredBy()
        print("\033[91mregisteredAccountId:", registeredAccountId, ", sessionId:", sessionAccountId)
        if registeredAccountId == sessionAccountId:
            print("게시글 삭제 완료\033[92m")
            self.__productRepository.deleteById(foundProduct.getId())
            return ProductDeleteResponse(True)

        print("게시글 작성자가 아니므로 삭제 할 수 없습니다")
        return ProductDeleteResponse(False)

    def searchProduct(self, *args, **kwargs):
        print("ProductService - searchProduct()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        productSearchRequest = ProductSearchRequest(*cleanedElements)

        searchedProductList = self.__productRepository.findByUserInputKeyword(
            productSearchRequest.getUserInputKeyword())

        searchedProductConvertedList = []

        for product in searchedProductList:
            searchedProductConvertedList.append({
                'productId': product.getId(),
                'name': product.getName(),
                'price': product.getPrice(),
                'registeredAccountId': self.__accountRepository.findById(product.getRegisteredBy()).getAccountId()
            })

        productListResponse = ProductListResponse(searchedProductConvertedList)
        print(f"Listing products: {productListResponse.getProductList()}")

        return productListResponse


