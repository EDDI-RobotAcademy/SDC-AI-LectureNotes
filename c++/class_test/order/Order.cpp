//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Order.h"

Order::Order(int _table_number) : table_number(_table_number) {

    std::cout << "주문하시겠습니까?" << std::endl;
}

Order::~Order() {

}

void Order::printMenu() {
    for(int i = 0; i<10;i++)
    {

        std::cout << "메뉴: " << menu[i] << std::endl;

    }

}

void Order::addMenu(std::string&& _menu) {
    for(int i = 0; i<10;i++)
    {
        menu[i] = _menu[i];
        std::cout << "메뉴: " << menu << std::endl;

    }

}
