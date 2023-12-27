

class ProductListResponse:
    __productList = []

    def __init__(self, productList):
        self.__productList = productList

    def getProductList(self):
        return self.__productList
