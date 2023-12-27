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

    def test_product_creation(self):
        account = self.accountRepository.findByAccountId('test')
        print(f"account: {account}")
        product = Product(name='item1', price=10, details='details1', registeredBy=account)
        print(f"product: {product}")

if __name__ == '__main__':
    unittest.main()
