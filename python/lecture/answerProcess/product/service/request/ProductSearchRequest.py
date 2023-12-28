from dataclasses import dataclass

from product.entity.Product import Product


@dataclass
class ProductSearchRequest:
    __userInputKeyword: str

    def __init__(self, userInputKeyword=None, **kwargs):
        if "__userInputKeyword" in kwargs:
            self.__userInputKeyword = kwargs["__userInputKeyword"]
        else:
            self.__userInputKeyword = userInputKeyword

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)

    def getUserInputKeyword(self):
        return self.__userInputKeyword


