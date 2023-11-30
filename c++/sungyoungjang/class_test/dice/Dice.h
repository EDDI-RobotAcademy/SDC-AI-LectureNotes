//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_DICE_H
#define CLASS_TEST_DICE_H


class Dice {
private: // 객체안의 내용을 아무나 못본다.
    const int DICE_MAX = 6;
    const int DICE_MIN = 1;
    int diceNumber;

public: // 객체안의 내용을 보려면 사용.
//    // intt_xxx_object
//    Dice(){
//    std::cout << "마! 내가 생성자다!" << std:: endl;
//    }
//    // free
//    ~Dice(){
//    std::cout << "난 죽을 때 출력됨" << std::endl;
//    }
    Dice();
    void rollDice();
    int getDiceNumber();
    ~Dice();
};


#endif //CLASS_TEST_DICE_H
