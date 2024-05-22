import unittest

from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from mysql.MySQLDatabase import MySQLDatabase
from order.entity.Order import Order
from order.repository.OrderRepositoryImpl import OrderRepositoryImpl
from product.entity.Product import Product
from product.repository.ProductRepositoryImpl import ProductRepositoryImpl


class TestOrderRepository(unittest.TestCase):
    def setUp(self):
        mysqlInstance = MySQLDatabase.getInstance()
        mysqlInstance.connect()

        self.productRepository = ProductRepositoryImpl()
        self.accountRepository = AccountRepositoryImpl()
        self.orderRepository = OrderRepositoryImpl()

    def test_save_and_find_by_account_id(self):
        accountId = "test"
        savedAccount = self.accountRepository.findByAccountId(accountId)
        accountUniqueId = savedAccount.getId()

        product = Product("test_product", 333, "test", accountUniqueId)
        savedProduct = self.productRepository.save(product)

        newOrder = Order(accountId=accountUniqueId, productId=savedProduct.getId())
        savedOrder = self.orderRepository.save(newOrder)

        self.assertIsNotNone(savedOrder)
        self.assertIsNotNone(savedOrder.getId())

        orderListByAccount = self.orderRepository.findAllByAccountId(accountUniqueId)

        self.assertTrue(orderListByAccount)

        for order in orderListByAccount:
            print("Order ID:", order.getId(), "Number1:", order.getAccountId(), "Number2:", order.getProductId())

if __name__ == '__main__':
    unittest.main()