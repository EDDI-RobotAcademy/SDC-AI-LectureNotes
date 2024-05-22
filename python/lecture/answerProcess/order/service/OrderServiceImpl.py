import json

from order.entity.Order import Order
from order.service.OrderService import OrderService
from order.service.request.OrderListRequest import OrderListRequest
from order.service.request.OrderRegisterRequest import OrderRegisterRequest
from order.service.response.OrderListResponse import OrderListResponse
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

    def orderList(self, *args, **kwargs):
        print("orderList()")

        cleanedElements = args[0]
        print(f"cleanedElements: {cleanedElements}")

        orderListRequest = OrderListRequest(*cleanedElements)

        sessionId = orderListRequest.getSessionId()
        orderByAccountList = self.__orderRepository.findAllByAccountId(sessionId)

        orderList = []

        for order in orderByAccountList:
            productId = order.getProductId()
            foundProduct = self.__productRepository.findById(productId)

            orderList.append({
                'productName': foundProduct.getName(),
                'price': foundProduct.getPrice(),
            })

        print(f"orderList: {orderList}")

        orderListResponse = OrderListResponse(orderList)
        print(f"orderListResponse: {orderListResponse}")

        return json.dumps(orderListResponse.toDict())

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


