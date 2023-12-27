from dataclasses import dataclass


@dataclass
class ProductListResponse:

    def __init__(self, productList):
        self.__productList = productList

    def getProductList(self):
        return self.__productList

    def __repr__(self):
        return f"ProductListResponse({self.__productList})"