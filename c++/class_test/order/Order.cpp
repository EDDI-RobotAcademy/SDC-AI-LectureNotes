//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Order.h"

Order::Order(int _table_number) : table_number(_table_number) {

}

Order::~Order() {

}

void Order::printMenu() {
    for(auto & i : menu)
    {
        std::cout << "메뉴: " << i << std::endl;
    }

}

void Order::addMenu(std::string & _menu) {
    menu[sizeof (menu)] = _menu;
}
