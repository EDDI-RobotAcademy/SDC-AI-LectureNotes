import unittest
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from mysql.MySQLDatabase import MySQLDatabase
from product.entity.Product import Product
from account.entity.Account import Account
from product.repository.ProductRepositoryImpl import ProductRepositoryImpl


class TestUglyProduct(unittest.TestCase):
    def setUp(self):
        # Create an in-memory SQLite database for testing
        mysqlInstance = MySQLDatabase.getInstance()
        mysqlInstance.connect()

        self.productRepository = ProductRepositoryImpl()
        self.accountRepository = AccountRepositoryImpl()

    def testProductCreation(self):
        account = self.accountRepository.findByAccountId('test')
        print(f"account: {account}")
        product = Product(name='item1', price=10, details='details1', registeredBy=account.getId())
        print(f"product: {product}")

    def testProductList(self):
        responseData = []
        productList = self.productRepository.findAll()
        for product in productList:
            print(f"Product ID: {product.getId()}, "
                  f"Name: {product.getName()}, "
                  f"Price: {product.getPrice()}, "
                  f"Details: {product.getDetails()}, "
                  f"Registered By: {self.accountRepository.findById(product.getRegisteredBy()).getAccountId()}")

            productData = {
                'productId': product.getId(),
                'name': product.getName(),
                'price': product.getPrice(),
                'details': product.getDetails(),
                'registeredAccountId': self.accountRepository.findById(product.getRegisteredBy()).getAccountId()
            }
            responseData.append(productData)

        print(responseData)

if __name__ == '__main__':
    unittest.main()
