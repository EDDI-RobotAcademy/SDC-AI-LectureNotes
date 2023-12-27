from product_form.repository.ProductFormRepository import ProductFormRepository
from utility.keyboard.KeyboardInput import KeyboardInput


class ProductFormRepositoryImpl(ProductFormRepository):
    __instance = None

    def __new__(cls):
        print("뭐가 문제인가 ?")
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    # def __init__(self):
    #     print("ProductFormRepositoryImpl 초기화 동작")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def createProductListForm(self):
        print("상품 리스트를 출력합니다")
        return

    def createProductRegisterForm(self):
        print("신규 상품을 등록합니다")
        userInputProductName = KeyboardInput.getKeyboardInput("상품명을 입력하세요:")
        userInputProductPrice = KeyboardInput.getKeyboardInput("상품 가격을 입력하세요:")
        userInputProductDetails = KeyboardInput.getKeyboardInput("상품 상세 정보를 입력하세요:")
        return userInputProductName, userInputProductPrice, userInputProductDetails


