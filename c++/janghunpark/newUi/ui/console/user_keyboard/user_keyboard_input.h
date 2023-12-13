//
// Created by eddi on 23. 12. 4.
//

#ifndef CLASS_TEST_USER_KEYBOARD_INPUT_H
#define CLASS_TEST_USER_KEYBOARD_INPUT_H

#define MAX_USER_KEYBOARD_INPUT         32

#include <iostream>

class user_keyboard_input {
public:
    void get_user_keyboard_input(std::string& keyboard_input);

    void get_user_keyboard_input_with_message(
            const std::string& output_message, std::string& keyboard_input);


    user_keyboard_input();
    ~user_keyboard_input();
};


#endif //CLASS_TEST_USER_KEYBOARD_INPUT_H
