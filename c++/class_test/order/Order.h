//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_ORDER_H
#define CLASS_TEST_ORDER_H


#include <string>
#include <vector>


class Order {
private:
    const int table_number;
    std::vector<std::string>  menuList;
public:
    Order(int);
    void addMenu(std::vector<std::string>&);
    void printMenu();
    ~Order();
};


#endif //CLASS_TEST_ORDER_H
