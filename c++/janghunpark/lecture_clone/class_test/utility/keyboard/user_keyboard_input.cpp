//
// Created by eddi on 23. 12. 5.
//

#include "user_keyboard_input.h"

#include <iostream>
#include <algorithm>

void get_user_keyboard_input_with_message(const std::string& output_message, std::string& keyboard_input)
{
    std::cout << output_message;
    std::getline(std::cin, keyboard_input);
    keyboard_input.erase(
            std::remove_if(keyboard_input.begin(),
                           keyboard_input.end(), ::isspace),
            keyboard_input.end());
}
