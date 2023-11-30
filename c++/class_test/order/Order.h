//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_ORDER_H
#define CLASS_TEST_ORDER_H


#include <string>



class Order {
private:
    const int table_number;
    std::string menu[10];
public:
    Order(int);
    void addMenu(std::string&);
    void printMenu();
    ~Order();
};


#endif //CLASS_TEST_ORDER_H
