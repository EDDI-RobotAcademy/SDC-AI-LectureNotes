# This is a sample Python script.
from account.entity.Account import Account


# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.
    print("{1}, {0}".format("Hello World", "안녕"))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')
    account = Account("hello", "hello")
    print(account)

    account.setAccountId("AC8")
    account.setPassword("호롤롤로로")
    print(account)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
