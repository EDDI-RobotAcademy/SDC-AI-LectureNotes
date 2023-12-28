from order.entity.Order import Order
from order.service.OrderService import OrderService
from order.service.request.OrderRegisterRequest import OrderRegisterRequest
from order.service.response.OrderRegisterResponse import OrderRegisterResponse


class OrderServiceImpl(OrderService):
    __instance = None

    def __new__(cls, accountRepository, sessionRepository, productRepository, orderRepository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__accountRepository = accountRepository
            cls.__instance.__sessionRepository = sessionRepository
            cls.__instance.__productRepository = productRepository
            cls.__instance.__orderRepository = orderRepository
        return cls.__instance

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def orderRegister(self, *args, **kwargs):
        print("registerOrder()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        orderRegisterRequest = OrderRegisterRequest(*cleanedElements)

        sessionId = orderRegisterRequest.getSessionId()
        productId = orderRegisterRequest.getProductId()
        order = Order(sessionId, productId)

        self.__orderRepository.save(order)

        return OrderRegisterResponse(True)


