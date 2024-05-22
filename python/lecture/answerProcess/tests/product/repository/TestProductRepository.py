import unittest
from sqlalchemy import create_engine, Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base

from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from mysql.MySQLDatabase import MySQLDatabase
from product.entity.Product import Product
from product.repository.ProductRepositoryImpl import ProductRepositoryImpl

Base = declarative_base()

class TestProductRepository(unittest.TestCase):
    def setUp(self):
        mysqlDatabase = MySQLDatabase.getInstance()
        mysqlDatabase.connect()

        self.productRepository = ProductRepositoryImpl()
        self.accountRepository = AccountRepositoryImpl()

    def testSave(self):
        account = self.accountRepository.findByAccountId('test')
        print(f"account: {account}")
        product = Product(name='item1', price=10, details='details1', registeredBy=account.getId())
        print(f"product: {product}")

        savedProduct = self.productRepository.save(product)

        self.assertIsNotNone(savedProduct)
        self.assertEqual(savedProduct.getName(), 'item1')
        self.assertEqual(savedProduct.getPrice(), 10)
        self.assertEqual(savedProduct.getDetails(), 'details1')

    def testFindByName(self):
        account = self.accountRepository.findByAccountId('test')
        product1 = Product(name='item1', price=10, details='details1', registeredBy=account.getId())
        product2 = Product(name='item2', price=20, details='details2', registeredBy=account.getId())

        self.productRepository.save(product1)
        self.productRepository.save(product2)

        foundProduct = self.productRepository.findByName('item1')

        self.assertIsNotNone(foundProduct)
        self.assertEqual(foundProduct.getName(), 'item1')
        self.assertEqual(foundProduct.getPrice(), 10)
        self.assertEqual(foundProduct.getDetails(), 'details1')

    def testDeleteById(self):
        account = self.accountRepository.findByAccountId('test')
        product = Product(name='item1', price=10, details='details1', registeredBy=account.getId())
        self.productRepository.save(product)

        productId = product.getId()
        self.productRepository.deleteById(productId)

        deletedProduct = self.productRepository.findById(productId)
        self.assertIsNone(deletedProduct)

if __name__ == '__main__':
    unittest.main()