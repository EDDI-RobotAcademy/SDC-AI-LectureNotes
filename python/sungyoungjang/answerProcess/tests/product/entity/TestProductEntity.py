import unittest

from account.entity.Account import Account
from product.entity.Product import Product


class TestProduct(unittest.TestCase):
    def test_product_creation(self):
        account = Account(accountId='user1', password='omg')

        product = Product(name='item1', price=10, details='details1', registeredBy=account)

        self.assertEqual(product.getName(), 'item1')
        self.assertEqual(product.getPrice(), 10)
        self.assertEqual(product.getDetails(), 'details1')
        self.assertEqual(product.getRegisteredBy().getAccountId(), 'user1')

if __name__ == '__main__':
    unittest.main()

