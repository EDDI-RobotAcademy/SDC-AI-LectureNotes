from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
from product_form.repository.ProductFormRepository import ProductFormRepository
from utility.keyboard.KeyboardInput import KeyboardInput


class ProductFormRepositoryImpl(ProductFormRepository):
    __instance = None

    def __new__(cls):
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
        userInputProductPrice = KeyboardInput.getKeyboardIntegerInput("상품 가격을 입력하세요:")
        userInputProductDetails = KeyboardInput.getKeyboardInput("상품 상세 정보를 입력하세요:")
        return userInputProductName, userInputProductPrice, userInputProductDetails

    def createProductReadForm(self):
        print("등록된 상품의 상세 정보를 살펴봅니다")
        userInputSelectedProductNumber = KeyboardInput.getKeyboardIntegerInput("어떤 상품의 상세 정보를 볼까요 ? (상품 번호 입력)")

        return userInputSelectedProductNumber

    def createProductUpdateForm(self):
        print("등록된 상품의 상세 정보를 수정합니다")

        userInputProductName = KeyboardInput.getKeyboardInput("수정 될 상품명을 입력하세요:")
        userInputProductPrice = KeyboardInput.getKeyboardIntegerInput("수정 될 상품 가격을 입력하세요:")
        userInputProductDetails = KeyboardInput.getKeyboardInput("수정 될 상품 상세 정보를 입력하세요:")
        return userInputProductName, userInputProductPrice, userInputProductDetails

    def createProductDeleteForm(self):
        print("등록된 상품을 삭제합니다")
        return

    def createProductSearchForm(self):
        print("상품을 검색합니다")

        userInputProductSearch = KeyboardInput.getKeyboardInput("검색 키워드를 입력하세요:")
        return userInputProductSearch



