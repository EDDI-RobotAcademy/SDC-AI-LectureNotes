# This is a sample Python script.
import random

from account.entity.Account import Account

from class_practice.Student import Student

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def print_hi(word):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {word}')  # Press Ctrl+F8 to toggle the breakpoint.


def play_dice_game_with_computer():
    name = input('당신의 이름은? ')
    your_dice_number = roll_dice()
    computer_dice_number = roll_dice()
    print(name, "님의 주사위 숫자는", your_dice_number)
    print("컴퓨터의 주사위 숫자는", computer_dice_number)
    if your_dice_number > computer_dice_number:
        print(f'{name}님의 승리입니다.')
    if your_dice_number < computer_dice_number:
        print("컴퓨터의 승리입니다.")
    if your_dice_number == computer_dice_number:
        print("무승부입니다.")


def roll_dice():
    random_number = random.randint(1, 6)
    return random_number


# Press the green button in the gutter to run the script.
if __name__ == '__main__': #int main(void) 와 같은 기능
    print_hi('Pycharm')
    print_hi('I want to be a good programmer.')
    test_list = ['apple', 'banana', 'cherry']
    int_list = [1, 2, 3, 4, 5]
    print(test_list)
    print(int_list)
    print(test_list[0:3])
    print(test_list+int_list)
    print("{}".format("This is me."))

    account = Account("", "")

    account.setAccountId("example Id")
    account.setPassword("new password")
    print(account)

    play_dice_game_with_computer()

    sampleStudent = Student("John", 17)
    print(sampleStudent.name, "is", sampleStudent.age, "years old, and he should ")
    sampleStudent.go_to_school()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
