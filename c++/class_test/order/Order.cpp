//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Order.h"

Order::Order(int _table_number) : table_number(_table_number) {

    std::cout << "주문하시겠습니까?" << std::endl;
}

Order::~Order() {
    std::cout << "4,400,000원입니다~" << std::endl;
}

void Order::printMenu() {
    for(int i = 0; i<menuList.size();i++)
    {

        std::cout << "메뉴: " << menuList[i] << std::endl;

    }

}

void Order::addMenu(std::vector<std::string> & _menuList) {
    menuList = _menuList;

}
