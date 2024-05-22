from order.repository.OrderFormRepository import OrderFormRepository
from utility.keyboard.KeyboardInput import KeyboardInput


class OrderFormRepositoryImpl(OrderFormRepository):
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

    def createOrderRegisterForm(self):
        print("상품을 주문합니다")
        userInputProductId = KeyboardInput.getKeyboardIntegerInput("주문하고 싶은 상품 번호를 입력하세요:")
        return userInputProductId

    def createOrderListForm(self):
        print("주문 내역을 살펴봅니다")
        return



